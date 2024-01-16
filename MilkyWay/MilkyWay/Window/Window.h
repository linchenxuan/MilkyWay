#pragma once

#include <string>
#include <cstdint>
#include <functional>
#include <GLFW/glfw3.h>

namespace MilkyWay
{
struct WindowOptions
{
    std::string Title;
    uint16_t Width;
    uint16_t Height;
};

enum class WindowStatus
{
    RUNNING,
    STOPED
};

class Window
{
public:
    using KeyCallbackFunc = void(Window *p_window, int p_key, int p_scancode, int p_action, int p_mods);
    using MouseCallback = void(Window *p_window, int p_button, int p_action, int p_mods);
    using FramebufferSizeCallback = void(Window *p_window, int p_width, int p_height);
    using CloseCallback = void(Window *p_window);

public:
    Window(const WindowOptions &p_options);

    ~Window();

public:
    void OnUpdate();

    void BindKeyCallback(KeyCallbackFunc p_func);
    const KeyCallbackFunc *GetKeyCallbackFunc() const;

    void BindMouseCallback(MouseCallback p_func);
    const MouseCallback *GetMouseCallback() const;

    void BindFramebufferSizeCallback(FramebufferSizeCallback p_func);
    const FramebufferSizeCallback *GetFramebufferSizeCallback() const;

    void BindCloseCallback(CloseCallback p_func);
    const CloseCallback *GetCloseCallback() const;

    void SetWindowStatus(WindowStatus p_status);
    WindowStatus GetWindowStatus();

    void Close();
    bool Closed();

private:
    WindowOptions m_options;
    WindowStatus m_status;
    GLFWwindow *m_glfwWindow;

    KeyCallbackFunc *m_keyCallbackFunc;
    MouseCallback *m_mouseCallback;
    FramebufferSizeCallback *m_framebufferSizeCallback;
    CloseCallback *m_closeCallback;
};
} // namespace MilkyWay
