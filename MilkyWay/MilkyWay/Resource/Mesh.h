#pragma once

#include "MilkyWay/Rendering/Defines.h"
#include "MilkyWay/Rendering/Buffers/VertexBuffer.h"
#include "MilkyWay/Rendering/Buffers/VertexArray.h"
#include "MilkyWay/Rendering/Vertex.h"
#include "MilkyWay/Rendering/Vertex.h"
#include "Texture.h"
#include "Shader.h"

#include <vector>
#include <memory>

namespace MilkyWay::Resource
{
class Mesh
{
public:
    Mesh(std::vector<Rendering::Vertex> &p_vertices, std::vector<uint32_t> &p_indices, std::shared_ptr<Shader> p_shader, std::shared_ptr<Texture> p_texture);

public:
    void Bind();

    void Unbind();

    uint32_t GetVertexCount()
    {
        return m_vertexCount;
    };

    uint32_t GetIndexCount()
    {
        return m_indicesCount;
    };

private:
    const uint32_t m_vertexCount;
    const uint32_t m_indicesCount;

    Rendering::VertexArray m_vertexArray;
    std::vector<float> m_vertexData;
    std::unique_ptr<Rendering::VertexBuffer> m_vertexBuffer;
    std::vector<uint32_t> &m_indicesData;
    std::unique_ptr<Rendering::IndexBuffer> m_indexBuffer;
    std::shared_ptr<Texture> m_texture;
    std::shared_ptr<Shader> m_shader;
};
} // namespace MilkyWay::Resource