#pragma once

#include <cstdint>

namespace MilkyWay::Rendering
{

class VertexBuffer
{
public:
    VertexBuffer();

public:
    void Bind();

    void Unbind();

    void SetData(void *p_data, size_t p_size);

private:
    uint32_t m_bufferID;
};

} // namespace MilkyWay::Rendering
