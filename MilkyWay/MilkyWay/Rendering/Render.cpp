#include "Render.h"

#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include <stdexcept>

namespace MilkyWay::Rendering
{
Renderer::Renderer()
{
    // glad: load all OpenGL function pointers
    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        throw std::runtime_error("Failed to initialize GLAD");
    }

    std::cout << "OpenGL Info:" << std::endl;
    std::cout << "  Vendor:" << glGetString(GL_VENDOR);
    std::cout << "  Renderer:" << glGetString(GL_RENDERER);
    std::cout << "  Version:" << glGetString(GL_VERSION) << std::endl;
}

void Renderer::SetClearColor(float p_red, float p_green, float p_blue, float p_alpha) const
{
    glClearColor(p_red, p_green, p_blue, p_alpha);
}
void Renderer::Clear(bool p_colorBuffer /* = true*/, bool p_depthBuffer /* = true*/, bool p_stencilBuffer /* = true*/) const
{
    glClear(
        (p_colorBuffer ? GL_COLOR_BUFFER_BIT : 0) | (p_depthBuffer ? GL_DEPTH_BUFFER_BIT : 0) | (p_stencilBuffer ? GL_STENCIL_BUFFER_BIT : 0));
}

void Renderer::Draw(Resource::Mesh &p_mesh, DrawType p_primitiveMode /* = DrawType::TRIANGLE*/)
{
    p_mesh.Bind();

    if (p_mesh.GetIndexCount() > 0)
    {
        glDrawElements(static_cast<GLenum>(p_primitiveMode), p_mesh.GetIndexCount(), GL_UNSIGNED_INT, nullptr);
    }
    else
    {
        glDrawArrays(static_cast<GLenum>(p_primitiveMode), 0, p_mesh.GetVertexCount());
    }

    p_mesh.Unbind();
}

} // namespace MilkyWay::Rendering
