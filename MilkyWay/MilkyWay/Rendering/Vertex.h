#pragma once

#include "MilkyWay/Math/Vector/Vector2.h"
#include "MilkyWay/Math/Vector/Vector3.h"

namespace MilkyWay::Rendering
{
struct Vertex
{
    Math::Vector3f Position;
    Math::Vector2f TexCoord;
};
} // namespace MilkyWay::Rendering