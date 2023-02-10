#pragma once

#include <XEngine.h>
#include "Light.h"

class LightManager
{
public:
    static LightManager* Get();

    void OnNewFrame();

    void AddDirectionalLight(const Vector3& direction);
    void AddPointLight(const Vector3& position, float constant, float linear, float quadratic);
    void AddSpotLight(const Vector3& position, const Vector3& direction, float constant, float linear, float quadratic, float decay);

    void SetLightingAmbient(const X::Color& color);
    void SetLightingDiffuse(const X::Color& color);
    void SetLightingSpecular(const X::Color& color);

    X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) const;

private:
    std::vector<std::unique_ptr<Light>> mLights;
    X::Color mAmbient = X::Colors::White;
    X::Color mDiffuse = X::Colors::White;
    X::Color mSpecular = X::Colors::White;
};