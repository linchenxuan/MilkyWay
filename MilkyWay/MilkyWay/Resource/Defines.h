#pragma once

namespace MilkyWay::Resource
{

enum class TextureFilter
{
    NEAREST = 0x2600,
    LINEAR = 0x2601,
    NEAREST_MIPMAP_NEAREST = 0x2700,
    LINEAR_MIPMAP_LINEAR = 0x2703,
    LINEAR_MIPMAP_NEAREST = 0x2701,
    NEAREST_MIPMAP_LINEAR = 0x2702
};

enum class TextureWrap
{
    REPEAT = 0x2901,
    CLAMP = 0x2900,
    MIRRORED_REPEAT = 0x8370,
    CLAMP_TO_EDGE = 0x812F,
    CLAMP_TO_BORDER = 0x812D
};

} // namespace MilkyWay::Resource