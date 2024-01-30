#include "IndexBuffer.h"
#include <glad/glad.h>

namespace MilkyWay::Rendering
{
IndexBuffer::IndexBuffer()
{
    glCreateBuffers(1, &m_bufferID);
}
IndexBuffer::~IndexBuffer()
{
    glDeleteBuffers(1, &m_bufferID);
}

void IndexBuffer::SetData(uint32_t *p_indices, uint32_t p_count)
{
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, p_count * sizeof(uint32_t), p_indices, GL_STATIC_DRAW);
}

void IndexBuffer::Bind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_bufferID);
}
void IndexBuffer::Unbind() const
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}
} // namespace MilkyWay::Rendering