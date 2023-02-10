#pragma once

#include "Command.h"

class CmdEnableDepth : public Command
{
public:
	const char* GetName()
	{
		return "EnableDepth";
	}
	const char* GetDescription()
	{
		return "EnableDepth(enable) enable or disable depth buffer";
	}

	bool Execute(const std::vector<std::string>& params);
};