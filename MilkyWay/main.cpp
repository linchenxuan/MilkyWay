#include "MilkyWay/Window/Window.h"
#include "MilkyWay/Rendering/Render.h"

#include <iostream>
#include <memory>

int main()
{
    MilkyWay::WindowOptions opts{
        "MilkyWay",
        1280,
        1024,
        4,
        6};

    MilkyWay::Window window(opts);

    window.BindKeyCallback([](MilkyWay::Window *p_window, int p_key, int p_scancode, int p_action, int p_mods) {
        std::cout << "key: " << p_key << " action: " << p_action << std::endl;
    });

    window.BindMouseCallback([](MilkyWay::Window *p_window, int p_button, int p_action, int p_mods) {
        std::cout << "button: " << p_button << " action: " << p_action << std::endl;
    });

    window.BindCloseCallback([](MilkyWay::Window *p_window) {
        p_window->Close();
    });

    window.BindFramebufferSizeCallback([](MilkyWay::Window *p_window, int width, int height) {
        glViewport(0, 0, width, height);
    });

    MilkyWay::Rendering::Renderer renderer;

    MilkyWay::Resource::TextureOptions textureOpts{
        MilkyWay::Resource::TextureFilter::NEAREST,
        MilkyWay::Resource::TextureFilter::NEAREST,
        MilkyWay::Resource::TextureWrap::REPEAT,
        true};

    const char *vertexShaderSource = R"(
                                    #version 330 core
                                    layout (location = 0) in vec3 aPos;
                                    layout (location = 1) in vec3 aTexCoord;
                                    
                                    out vec2 TexCoord;
                                    void main()
                                    {
                                        gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);
                                        TexCoord = vec2(aTexCoord.x, aTexCoord.y);
                                    }
    )";

    const char *fragmentShaderSource = R"(
                                    #version 330 core
                                    out vec4 FragColor;
                                    in vec2 TexCoord;
                                    
                                    // texture samplers
                                    uniform sampler2D texture1;

                                    void main()
                                    {
	                                    FragColor = texture(texture1, TexCoord);
                                    }
    )";

    std::shared_ptr<MilkyWay::Resource::Shader> shader = std::make_shared<MilkyWay::Resource::Shader>(vertexShaderSource, fragmentShaderSource);

    std::vector<MilkyWay::Rendering::Vertex> p_vertices{
        {{0.5f, 0.5f, 0.0f}, {0.0f, 0.0f}},
        {{0.5f, -0.5f, 0.0f}, {0.0f, 1.0f}},
        {{-0.5f, -0.5f, 0.0f}, {1.0f, 1.0f}},
        {{-0.5f, 0.5f, 0.0f}, {1.0f, 0.0f}}};

    std::vector<uint32_t> p_indices{
        0, 1, 3,
        1, 2, 3};

    std::shared_ptr<MilkyWay::Resource::Texture2D> texture2D = std::make_shared<MilkyWay::Resource::Texture2D>("../../../../MilkyWay/Resources/panda.jpg", textureOpts);

    MilkyWay::Resource::Mesh mesh(p_vertices, p_indices, shader, texture2D);

    while (!window.Closed())
    {
        renderer.Draw(mesh, MilkyWay::Rendering::DrawType::TRIANGLES);
        window.OnUpdate();
    }
}
