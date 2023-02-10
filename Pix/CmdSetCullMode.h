#pragma once

#include "Command.h"

class CmdSetCullMode : public Command
{
public:
	const char* GetName()
	{
		return "SetCullMode";
	}
	const char* GetDescription()
	{
		return "SetCullMode(cullMode) sets the triangle cull mode";
	}

	bool Execute(const std::vector<std::string>& params);
};