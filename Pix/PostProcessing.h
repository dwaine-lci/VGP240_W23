#pragma once

#include <XEngine.h>
#include "RenderTarget.h"

enum class EffectType
{
    None,
    Monochrome,
    Invert,
    Mirror,
    Blur,
    ColorMaskR,
    ColorMaskG,
    ColorMaskB,
    Sepia,
    Wave
};

class PostProcessing final
{
public:
    static PostProcessing* Get();

    void Initialize(int width, int height, const X::Color& clearColor = X::Colors::Black);
    void OnNewFrame();
    void SetPostProcessingEffect(EffectType effectType);
    void BeginDraw();
    bool DrawToRenderTarget(int x, int y, const X::Color& color);
    void EndDraw();

private:
    void DrawPixel(int x, int y);

    int mWidth = 0;
    int mHeight = 0;
    bool mDrawBegin = false;
    X::Color mClearColor = X::Colors::Black;
    EffectType mEffectType = EffectType::None;
    RenderTarget mRenderTarget;
};