#pragma once

#include "Command.h"

class CmdSetPostProcessingEffect : public Command
{
public:
	const char* GetName()
	{
		return "SetPostProcessingEffect";
	}
	const char* GetDescription()
	{
		return "SetPostProcessingEffect(effect) sets the post processing effect";
	}

	bool Execute(const std::vector<std::string>& params);
};