#pragma once

#include "MilkyWay/Math/Vector/Vector3.h"
#include "MilkyWay/Resource/Mesh.h"
#include "MilkyWay/Resource/Shader.h"
#include "Defines.h"

namespace MilkyWay::Rendering
{
class Renderer
{
public:
    Renderer();

public:
    void SetClearColor(float p_red, float p_green, float p_blue, float p_alpha) const;
    void Clear(bool p_colorBuffer = true, bool p_depthBuffer = true, bool p_stencilBuffer = true) const;

    void Draw(Resource::Mesh &p_mes, DrawType p_primitiveMode = DrawType::TRIANGLES);
};
} // namespace MilkyWay::Rendering
