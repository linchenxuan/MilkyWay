#include "VertexArray.h"

#include <glad/glad.h>

namespace MilkyWay::Rendering
{

VertexArray::VertexArray()
{
    glCreateVertexArrays(1, &m_bufferID);
}

VertexArray::~VertexArray()
{
    glDeleteVertexArrays(1, &m_bufferID);
}

void VertexArray::BindAttribute(uint64_t p_count, unsigned int p_type, uint64_t p_stride, intptr_t p_offset)
{
    glVertexAttribPointer(m_vertexBufferIndex,
                          p_count,
                          p_type,
                          GL_FALSE,
                          p_stride,
                          reinterpret_cast<const GLvoid *>(p_offset));
    glEnableVertexAttribArray(m_vertexBufferIndex);

    m_vertexBufferIndex++;
}

void VertexArray::Bind() const
{
    glBindVertexArray(m_bufferID);
}

void VertexArray::UnBind() const
{
    glBindVertexArray(0);
}

} // namespace MilkyWay::Rendering