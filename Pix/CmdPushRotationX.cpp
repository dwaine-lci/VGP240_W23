#include "CmdPushRotationX.h"
#include "VariableCache.h"
#include "MatrixStack.h"

bool CmdPushRotationX::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	auto degree = VariableCache::Get()->GetFloat(params[0]);

	MatrixStack::Get()->PushRotationX(degree * 3.1416f / 180.0f);
	return true;
}
