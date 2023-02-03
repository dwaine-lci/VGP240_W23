#pragma once

#include "Command.h"

class CmdPopMatrix : public Command
{
public:
	const char* GetName() override
	{
		return "PopMatrix";
	}

	const char* GetDescription() override
	{
		return
			"PopMatrix()\n"
			"\n"
			"- pops a matrix from the stack.";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
