#pragma once
#include "Command.h"

class CmdEndPostProcessingDraw : public Command
{
public:
	const char* GetName()
	{
		return "EndPostProcessingDraw";
	}
	const char* GetDescription()
	{
		return "EndPostProcessingDraw() using applies effect to render target";
	}

	bool Execute(const std::vector<std::string>& params);
};