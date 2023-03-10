#include "CmdBeginPostProcessingDraw.h"
#include "PostProcessing.h"

bool CmdBeginPostProcessingDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->BeginDraw();
	return true;
}