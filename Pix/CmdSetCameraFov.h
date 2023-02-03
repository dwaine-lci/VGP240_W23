#pragma once

#include "Command.h"

class CmdSetCameraFov : public Command
{
public:
	const char* GetName() override
	{
		return "SetCameraFov";
	}

	const char* GetDescription() override
	{
		return
			"SetCameraFov(radians)\n"
			"\n"
			"- Pushes a rotation in the x axis into the matrix stack (rad).";
	}

	bool Execute(const std::vector<std::string>& params) override;
};
