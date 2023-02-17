#pragma once

#include "Light.h"

class PointLight : public Light
{
public:
    virtual X::Color ComputeLightColor(const Vector3& position, const Vector3& normal) const override;

    void SetPosition(const Vector3& position);
    void SetAttenuation(float constant, float linear, float quadratic);

private:
    Vector3 mPosition;
    float mAttenConst = -1.0f;
    float mAttenLinear = 0.0f;
    float mAttenQuad = 0.0f;
};