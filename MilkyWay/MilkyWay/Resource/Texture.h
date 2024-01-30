#pragma once

#include "Defines.h"

#include <cstdint>
#include <string>

namespace MilkyWay::Resource
{

struct TextureOptions
{
    TextureFilter MinFilter;
    TextureFilter MagFilter;
    TextureWrap Wrap;
    bool NeedMipMap;
};

class Texture
{
public:
    virtual ~Texture()
    {
    }
    virtual void Bind(uint32_t slot = 0) const = 0;
    virtual void UnBind() const = 0;
    virtual uint32_t GetTextureID() = 0;
};

class Texture2D : public Texture
{
public:
    Texture2D(const std::string &p_filepath, TextureOptions p_options);
    ~Texture2D();
    Texture2D(Texture2D &) = delete;
    Texture2D(Texture2D &&) = delete;

    void Bind(uint32_t slot = 0) const override;
    void UnBind() const override;

    uint32_t GetTextureID()
    {
        return m_textureID;
    }

private:
    uint32_t m_textureID;
    std::string m_path;
    int m_width, m_height;
    TextureOptions m_options;
};

} // namespace MilkyWay::Resource