#pragma once

#include <cstdint>

namespace MilkyWay::Rendering
{
class IndexBuffer
{
public:
    IndexBuffer();
    ~IndexBuffer();

public:
    void Bind() const;
    void Unbind() const;
    void SetData(uint32_t *p_indices, uint32_t p_count);

private:
    uint32_t m_bufferID;
};
} // namespace MilkyWay::Rendering