#include "VertexBuffer.h"

#include <glad/glad.h>

namespace MilkyWay::Rendering
{

VertexBuffer::VertexBuffer()
{
    glCreateBuffers(1, &m_bufferID);
}

void VertexBuffer::SetData(void *p_data, size_t p_size)
{
    glBufferData(GL_ARRAY_BUFFER, p_size, p_data, GL_DYNAMIC_DRAW);
}

void VertexBuffer::Bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, m_bufferID);
}

void VertexBuffer::Unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, 0);
}
} // namespace MilkyWay::Rendering
