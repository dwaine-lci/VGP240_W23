#pragma once

#include "Command.h"

class CmdSetAddressMode : public Command
{
public:
	const char* GetName()
	{
		return "SetAddressMode";
	}
	const char* GetDescription()
	{
		return "SetAddressMode(addressmode) sets the texture address mode";
	}

	bool Execute(const std::vector<std::string>& params);
};