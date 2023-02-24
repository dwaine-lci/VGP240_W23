#pragma once

#include "Vertex.h"

enum class Topology
{
	Point,
	Line,
	Triangle
};

enum class CullMode
{
	None,
	Front, // cull items that are front facing
	Back // cull items facing away from the camera
};

class PrimitivesManager
{
public:
	static PrimitivesManager* Get();

	void OnNewFrame();
	void SetCullMode(CullMode mode);
	void SetCorrectUV(bool correct);

	bool BeginDraw(Topology topology, bool applyTransform = false);
	void AddVertex(const Vertex& vertex);
	bool EndDraw();

private:
	std::vector<Vertex> mVertexBuffer;
	Topology mTopology = Topology::Triangle;
	CullMode mCullMode = CullMode::None;
	bool mDrawBegin = false;
	bool mApplyTransform = false;
	bool mCorrectUV = true;
};