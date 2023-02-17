#pragma once

#include "Model.h"

class ModelCache
{
public:
    static ModelCache* Get();

    void Clear();
    const Model* GetModel(const std::string& fileName);

private:
    std::vector<std::unique_ptr<Model>> mModels;
};