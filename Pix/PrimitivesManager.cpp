#include "PrimitivesManager.h"
#include "Rasterizer.h"
#include "Clipper.h"
#include "Camera.h"
#include "MatrixStack.h"
#include "LightManager.h"

extern float gResolutionX;
extern float gResolutionY;

namespace
{
	Matrix4 GetScreenTransform()
	{
		float hw = gResolutionX * 0.5f;
		float hh = gResolutionY * 0.5f;
		return Matrix4(
			  hw, 0.0f, 0.0f, 0.0f,
			0.0f,  -hh, 0.0f, 0.0f,
			0.0f, 0.0f, 1.0f, 0.0f,
			  hw,   hh, 0.0f, 1.0f
		);
	}

	bool CullTriangle(CullMode mode, const std::vector<Vertex>& triangleInNDC)
	{
		if (mode != CullMode::None)
		{
			Vector3 abDir = triangleInNDC[1].pos - triangleInNDC[0].pos;
			Vector3 acDir = triangleInNDC[2].pos - triangleInNDC[0].pos;
			Vector3 faceNorm = MathHelper::Normalize(MathHelper::Cross(abDir, acDir));
			if (mode == CullMode::Back && faceNorm.z > 0.0f)
			{
				return true;
			}
			else if (mode == CullMode::Front && faceNorm.z < 0.0f)
			{
				return true;
			}
		}
		return false;
	}
}

PrimitivesManager* PrimitivesManager::Get()
{
	static PrimitivesManager sInstance;
	return &sInstance;
}

void PrimitivesManager::OnNewFrame()
{
	mCullMode = CullMode::Back;
}

void PrimitivesManager::SetCullMode(CullMode mode)
{
	mCullMode = mode;
}

bool PrimitivesManager::BeginDraw(Topology topology, bool applyTransform)
{
	mDrawBegin = true;
	mTopology = topology;
	mApplyTransform = applyTransform;
	mVertexBuffer.clear();
	return true;
}

void PrimitivesManager::AddVertex(const Vertex& vertex)
{
	if (mDrawBegin)
	{
		mVertexBuffer.push_back(vertex);
	}
}

bool PrimitivesManager::EndDraw()
{
	if (!mDrawBegin)
	{
		return false;
	}

	Matrix4 matWorld = MatrixStack::Get()->GetTransform();
	Matrix4 matView = Camera::Get()->GetViewMatrix();
	Matrix4 matProj = Camera::Get()->GetProjectionMatrix();
	Matrix4 matScreen = GetScreenTransform();
	Matrix4 matNDC = matView * matProj;

	if (mApplyTransform)
	{
		Matrix4 matFinal = matWorld;
		if (mTopology != Topology::Triangle)
		{
			matFinal = matFinal * matView * matProj * matScreen;
		}
		for (size_t i = 0; i < mVertexBuffer.size(); ++i)
		{
			mVertexBuffer[i].pos = MathHelper::TransformCoord(mVertexBuffer[i].pos, matFinal);
			mVertexBuffer[i].posWorld = mVertexBuffer[i].pos;
			mVertexBuffer[i].normal = MathHelper::TransformNormal(mVertexBuffer[i].normal, matFinal);
		}
	}

	switch (mTopology)
	{
		case Topology::Point:
			for (size_t i = 0; i < mVertexBuffer.size(); ++i)
			{
				if (!Clipper::Get()->ClipPoint(mVertexBuffer[i]))
				{
					Rasterizer::Get()->DrawPoint(mVertexBuffer[i]);
				}
			}
			break;
		case Topology::Line:
			for (size_t i = 1; i < mVertexBuffer.size(); i += 2)
			{
				if (!Clipper::Get()->ClipLine(mVertexBuffer[i - 1], mVertexBuffer[i]))
				{
					Rasterizer::Get()->DrawLine(mVertexBuffer[i - 1], mVertexBuffer[i]);
				}
			}
			break;
		case Topology::Triangle:
			for (size_t i = 2; i < mVertexBuffer.size(); i += 3)
			{
				std::vector<Vertex> triangle = { mVertexBuffer[i - 2], mVertexBuffer[i - 1], mVertexBuffer[i] };
				if (mApplyTransform)
				{
					if (MathHelper::CheckEqual(MathHelper::MagnitudeSquared(triangle[0].normal), 0.0f))
					{
						Vector3 abDir = triangle[1].pos - triangle[0].pos;
						Vector3 acDir = triangle[2].pos - triangle[0].pos;
						Vector3 faceNorm = MathHelper::Normalize(MathHelper::Cross(abDir, acDir));
						for (size_t v = 0; v < triangle.size(); ++v)
						{
							triangle[v].normal = faceNorm;
						}
					}

					if (Rasterizer::Get()->GetShadeMode() != ShadeMode::Phong)
					{
						// apply lighting in world space
						for (size_t v = 0; v < triangle.size(); ++v)
						{
							triangle[v].color *= LightManager::Get()->ComputeLightColor(triangle[v].pos, triangle[v].normal);
						}
					}

					// convert world space to NDC space
					for (size_t v = 0; v < triangle.size(); ++v)
					{
						triangle[v].pos = MathHelper::TransformCoord(triangle[v].pos, matNDC);
					}

					// check if culled in ndc space
					if (CullTriangle(mCullMode, triangle))
					{
						continue;
					}

					// convert ndc space to screen space
					for (size_t v = 0; v < triangle.size(); ++v)
					{
						triangle[v].pos = MathHelper::TransformCoord(triangle[v].pos, matScreen);
					}
				}
				if (!Clipper::Get()->ClipTriangle(triangle))
				{
					for (size_t v = 2; v < triangle.size(); ++v)
					{
						Rasterizer::Get()->DrawTriangle(triangle[0], triangle[v - 1], triangle[v]);
					}
				}
			}
			break;
		default:
			return false;
	}
	
	mDrawBegin = false;

	return true;
}