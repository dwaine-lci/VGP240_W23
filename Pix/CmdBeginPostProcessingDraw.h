#pragma once

#include "Command.h"

class CmdBeginPostProcessingDraw : public Command
{
public:
	const char* GetName()
	{
		return "BeginPostProcessingDraw";
	}
	const char* GetDescription()
	{
		return "BeginPostProcessingDraw() begins drawing to the render target";
	}

	bool Execute(const std::vector<std::string>& params);
};