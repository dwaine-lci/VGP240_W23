#pragma once

#include "Command.h"

class CmdSetCorrectUV : public Command
{
public:
	const char* GetName()
	{
		return "SetCorrectUV";
	}
	const char* GetDescription()
	{
		return "SetCorrectUV(enable) enable or disable setting the correct UV";
	}

	bool Execute(const std::vector<std::string>& params);
};