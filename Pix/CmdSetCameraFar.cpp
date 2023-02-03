#include "CmdSetCameraFar.h"
#include "VariableCache.h"
#include "Camera.h"

bool CmdSetCameraFar::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	auto value = VariableCache::Get()->GetFloat(params[0]);
	Camera::Get()->SetFarPlane(value);
	return true;
}
