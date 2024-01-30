#include "Mesh.h"

#include <iostream>

namespace MilkyWay::Resource
{
Mesh::Mesh(std::vector<Rendering::Vertex> &p_vertices, std::vector<uint32_t> &p_indices, std::shared_ptr<Shader> p_shader, std::shared_ptr<Texture> p_texture) :
    m_vertexCount(static_cast<uint32_t>(p_vertices.size())),
    m_indicesCount(static_cast<uint32_t>(p_indices.size())),
    m_indicesData(p_indices),
    m_texture(p_texture),
    m_shader(p_shader)
{
    for (const auto &vertex : p_vertices)
    {
        m_vertexData.push_back(vertex.Position[0]);
        m_vertexData.push_back(vertex.Position[1]);
        m_vertexData.push_back(vertex.Position[2]);

        m_vertexData.push_back(vertex.TexCoord[0]);
        m_vertexData.push_back(vertex.TexCoord[1]);
    }

    m_vertexBuffer = std::make_unique<Rendering::VertexBuffer>();
    m_indexBuffer = std::make_unique<Rendering::IndexBuffer>();
}

void Mesh::Bind()
{
    m_vertexArray.Bind();

    m_vertexBuffer->Bind();
    m_vertexBuffer->SetData(m_vertexData.data(), m_vertexData.size() * sizeof(float));

    m_indexBuffer->Bind();
    m_indexBuffer->SetData(m_indicesData.data(), m_indicesData.size());

    m_vertexArray.BindAttribute(3, 0x1406, sizeof(Rendering::Vertex), 0);
    m_vertexArray.BindAttribute(2, 0x1406, sizeof(Rendering::Vertex), sizeof(float) * 3);

    m_shader->Bind();

    m_texture->Bind();

    // m_shader->SetUniformInt("texture1", 0);
}

void Mesh::Unbind()
{
    m_vertexArray.UnBind();
    m_vertexBuffer->Unbind();
    m_indexBuffer->Unbind();
    m_shader->Unbind();
    m_texture->UnBind();
}

} // namespace MilkyWay::Resource