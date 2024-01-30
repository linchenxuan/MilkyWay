#include "Texture.h"

#include <stb_image.h>
#include <glad/glad.h>
#include <iostream>

namespace MilkyWay::Resource
{
Texture2D::Texture2D(const std::string &p_filepath, TextureOptions p_options) :
    m_path(p_filepath),
    m_options(p_options)
{
    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, static_cast<GLint>(m_options.Wrap));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, static_cast<GLint>(m_options.Wrap));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(m_options.MinFilter));
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(m_options.MagFilter));

    int bitsPerPixel;

    unsigned char *dataBuffer = stbi_load(p_filepath.c_str(), &m_width, &m_height, &bitsPerPixel, 0);

    if (dataBuffer == nullptr)
    {
        std::cout << "Texture Load Faild\n";
    }

    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, m_width, m_height, 0, GL_RGB, GL_UNSIGNED_BYTE, dataBuffer);

    if (p_options.NeedMipMap)
    {
        glGenerateMipmap(GL_TEXTURE_2D);
    }

    glBindTexture(GL_TEXTURE_2D, 0);
    stbi_image_free(dataBuffer);
}

Texture2D::~Texture2D()
{
    UnBind();
}

void Texture2D::Bind(uint32_t p_slot) const
{
    glActiveTexture(GL_TEXTURE0 + p_slot);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void Texture2D::UnBind() const
{
    glBindTexture(GL_TEXTURE_2D, 0);
}
} // namespace MilkyWay::Resource
