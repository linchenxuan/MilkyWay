#include "Shader.h"

#include <glad/glad.h>

#include <iostream>
#include <fstream>
#include <sstream>

namespace MilkyWay::Resource
{

Shader::Shader(const std::string &p_filePath) :
    m_filePath(p_filePath)
{
    std::pair<std::string, std::string> source = ParseShader(p_filePath);

    m_shaderID = CreateProgram(source.first, source.second);
}

Shader::Shader(const std::string &p_vertexShader, const std::string &p_fragmentShader)
{
    m_shaderID = CreateProgram(p_vertexShader, p_fragmentShader);
}

Shader::~Shader()
{
    glDeleteProgram(m_shaderID);
}

void Shader::Bind() const
{
    glUseProgram(m_shaderID);
}

void Shader::Unbind() const
{
    glUseProgram(0);
}

void Shader::SetUniformInt(const std::string &p_name, int p_value)
{
    glUniform1i(glGetUniformLocation(m_shaderID, p_name.data()), p_value);
}

void Shader::SetUniformFloat(const std::string &p_name, float p_value)
{
    glUniform1f(glGetUniformLocation(m_shaderID, p_name.data()), p_value);
}

void Shader::SetUniformVec2(const std::string &p_name, const Math::Vector2f &p_vec2)
{
    glUniform2f(glGetUniformLocation(m_shaderID, p_name.data()), p_vec2.X, p_vec2.Y);
}

void Shader::SetUniformVec3(const std::string &p_name, const Math::Vector3f &p_vec3)
{
    glUniform3f(glGetUniformLocation(m_shaderID, p_name.data()), p_vec3.X, p_vec3.Y, p_vec3.Z);
}

int Shader::GetUniformInt(const std::string &p_name)
{
    int value;
    glGetUniformiv(m_shaderID, glGetUniformLocation(m_shaderID, p_name.data()), &value);
    return value;
}

float Shader::GetUniformFloat(const std::string &p_name)
{
    float value;
    glGetUniformfv(m_shaderID, glGetUniformLocation(m_shaderID, p_name.data()), &value);
    return value;
}

Math::Vector2f Shader::GetUniformVec2(const std::string &p_name)
{
    GLfloat values[2];
    glGetUniformfv(m_shaderID, glGetUniformLocation(m_shaderID, p_name.data()), values);
    return reinterpret_cast<Math::Vector2f &>(values);
}

Math::Vector3f Shader::GetUniformVec3(const std::string &p_name)
{
    GLfloat values[3];
    glGetUniformfv(m_shaderID, glGetUniformLocation(m_shaderID, p_name.data()), values);
    return reinterpret_cast<Math::Vector3f &>(values);
}

std::pair<std::string, std::string> Shader::ParseShader(const std::string &p_filePath)
{
    std::ifstream stream(p_filePath.data());

    enum class ShaderType
    {
        NONE = -1,
        VERTEX = 0,
        FRAGMENT = 1
    };

    std::string line;

    std::stringstream ss[2];

    ShaderType type = ShaderType::NONE;

    while (std::getline(stream, line))
    {
        if (line.find("#shader") != std::string::npos)
        {
            if (line.find("vertex") != std::string::npos)
                type = ShaderType::VERTEX;
            else if (line.find("fragment") != std::string::npos)
                type = ShaderType::FRAGMENT;
        }
        else if (type != ShaderType::NONE)
        {
            ss[static_cast<int>(type)] << line << '\n';
        }
    }

    return {
        ss[static_cast<int>(ShaderType::VERTEX)].str(),
        ss[static_cast<int>(ShaderType::FRAGMENT)].str()};
}

uint32_t Shader::CompileShader(uint32_t p_type, const std::string &p_source)
{
    const uint32_t m_shaderID = glCreateShader(p_type);
    const char *src = p_source.c_str();
    glShaderSource(m_shaderID, 1, &src, nullptr);
    glCompileShader(m_shaderID);

    // check for shader compile errors
    int success;
    char infoLog[512];
    glGetShaderiv(m_shaderID, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(m_shaderID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n"
                  << infoLog << std::endl;
        return 0;
    }

    return m_shaderID;
}

uint32_t Shader::CreateProgram(const std::string &p_vertexShader, const std::string &p_fragmentShader)
{
    const uint32_t vs = CompileShader(GL_VERTEX_SHADER, p_vertexShader.data());
    const uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, p_fragmentShader.data());

    if (vs == 0 || fs == 0)
        return 0;

    const uint32_t program = glCreateProgram();
    glAttachShader(program, vs);
    glAttachShader(program, fs);
    glLinkProgram(program);

    GLint linkStatus;
    glGetProgramiv(program, GL_LINK_STATUS, &linkStatus);

    if (!linkStatus)
    {
        char infoLog[512];
        glGetProgramInfoLog(program, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n"
                  << infoLog << std::endl;
        return 0;
    }

    glDeleteShader(vs);
    glDeleteShader(fs);

    return program;
}

} // namespace MilkyWay::Resource