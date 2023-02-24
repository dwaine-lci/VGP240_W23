#pragma once

#include <XEngine.h>

enum class AddressMode : int
{
    Clamp,
    Wrap,
    Mirror,
    Border
};

class Texture // it'll only load 24 bit bmps
{
public:
    void Load(const std::string& fileName);
    const std::string& GetFileName() const;
    X::Color GetPixel(float u, float v, AddressMode mode) const;

private:
    std::string mFileName;
    std::unique_ptr<X::Color[]> mPixels;
    int mWidth = 0;
    int mHeight = 0;
};