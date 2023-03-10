#include "CmdEndPostProcessingDraw.h"
#include "PostProcessing.h"

bool CmdEndPostProcessingDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->EndDraw();
	return true;
}