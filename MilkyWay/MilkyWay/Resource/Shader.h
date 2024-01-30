#pragma once

#include "MilkyWay/Math/Vector/Vector2.h"
#include "MilkyWay/Math/Vector/Vector3.h"

#include <string_view>

namespace MilkyWay::Resource
{

class Shader
{
public:
    Shader(const std::string &p_filePath);
    Shader(const std::string &p_vertexShader, const std::string &p_fragmentShader);

    ~Shader();

public:
    void Bind() const;

    void Unbind() const;

    void SetUniformInt(const std::string &p_name, int p_value);

    void SetUniformFloat(const std::string &p_name, float p_value);

    void SetUniformVec2(const std::string &p_name, const Math::Vector2f &p_vec2);

    void SetUniformVec3(const std::string &p_name, const Math::Vector3f &p_vec3);

    int GetUniformInt(const std::string &p_name);

    float GetUniformFloat(const std::string &p_name);

    Math::Vector2f GetUniformVec2(const std::string &p_name);

    Math::Vector3f GetUniformVec3(const std::string &p_name);

private:
    std::pair<std::string, std::string> ParseShader(const std::string &p_filePath);
    uint32_t CompileShader(uint32_t p_type, const std::string &p_source);
    uint32_t CreateProgram(const std::string &p_vertexShader, const std::string &p_fragmentShader);

private:
    uint32_t m_shaderID;
    std::string m_filePath;
};
} // namespace MilkyWay::Resource