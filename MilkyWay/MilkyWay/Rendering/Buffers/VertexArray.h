#pragma once

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include <vector>

namespace MilkyWay::Rendering
{
class VertexArray
{
public:
    VertexArray();

    ~VertexArray();

public:
    void BindAttribute(uint64_t p_count, unsigned int p_type, uint64_t p_stride, intptr_t p_offset);

    void Bind() const;

    void UnBind() const;

private:
    uint32_t m_bufferID;
    uint32_t m_vertexBufferIndex = 0;
};
} // namespace MilkyWay::Rendering