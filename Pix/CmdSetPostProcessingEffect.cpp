#include "CmdSetPostProcessingEffect.h"
#include "PostProcessing.h"

bool CmdSetPostProcessingEffect::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1)
	{
		return false;
	}

	EffectType effectType = EffectType::None;
	if (params[0] == "none") { effectType = EffectType::None; }
	else if (params[0] == "monochrome") { effectType = EffectType::Monochrome; }
	else if (params[0] == "invert") { effectType = EffectType::Invert; }
	else if (params[0] == "mirror") { effectType = EffectType::Mirror; }
	else if (params[0] == "blur") { effectType = EffectType::Blur; }
	else if (params[0] == "colormaskr") { effectType = EffectType::ColorMaskR; }
	else if (params[0] == "colormaskg") { effectType = EffectType::ColorMaskG; }
	else if (params[0] == "colormaskb") { effectType = EffectType::ColorMaskB; }
	else if (params[0] == "sepia") { effectType = EffectType::Sepia; }
	else if (params[0] == "wave") { effectType = EffectType::Wave; }
	else { return false; }

	PostProcessing::Get()->SetPostProcessingEffect(effectType);
	return true;
}