#include "CmdSetClipping.h"

#include "Clipper.h"

bool CmdSetClipping::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
		return false;

	bool setClipping = params[0] == "true";
	Clipper::Get()->SetClipping(setClipping);
	return true;
}
