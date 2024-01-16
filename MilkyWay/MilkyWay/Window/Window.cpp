
#include "Window.h"

namespace MilkyWay
{

Window::Window(const WindowOptions &p_options) :
    m_options(p_options)
{
    if (!glfwInit())
        _ASSERT(0);

    m_glfwWindow = glfwCreateWindow(m_options.Width, m_options.Height, m_options.Title.data(), NULL, NULL);
    m_status = WindowStatus::RUNNING;

    glfwSetWindowUserPointer(m_glfwWindow, this);
}

Window::~Window()
{
    glfwDestroyWindow(m_glfwWindow);
    glfwTerminate();
}

void Window::OnUpdate()
{
    glfwSwapBuffers(m_glfwWindow);
    glfwPollEvents();
}

void Window::BindKeyCallback(KeyCallbackFunc p_func)
{
    m_keyCallbackFunc = p_func;

    glfwSetKeyCallback(m_glfwWindow, [](GLFWwindow *p_window, int p_key, int p_scancode, int p_action, int p_mods) {
        Window *window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(p_window));
        if (window == nullptr)
        {
            _ASSERT(0);
        }
        const Window::KeyCallbackFunc *cb = window->GetKeyCallbackFunc();
        cb(window, p_key, p_scancode, p_action, p_mods);
    });
}
void Window::BindMouseCallback(MouseCallback p_func)
{
    m_mouseCallback = p_func;

    glfwSetMouseButtonCallback(m_glfwWindow, [](GLFWwindow *p_window, int p_button, int p_action, int p_mods) {
        Window *window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(p_window));
        if (window == nullptr)
        {
            _ASSERT(0);
        }
        const Window::MouseCallback *cb = window->GetMouseCallback();

        cb(window, p_button, p_action, p_mods);
    });
}

void Window::BindFramebufferSizeCallback(FramebufferSizeCallback p_func)
{
    m_framebufferSizeCallback = p_func;

    glfwSetFramebufferSizeCallback(m_glfwWindow, [](GLFWwindow *p_window, int p_width, int p_height) {
        Window *window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(p_window));
        if (window == nullptr)
        {
            _ASSERT(0);
        }
        const Window::FramebufferSizeCallback *cb = window->GetFramebufferSizeCallback();

        cb(window, p_width, p_height);
    });
}

void Window::BindCloseCallback(CloseCallback p_func)
{
    m_closeCallback = p_func;

    glfwSetWindowCloseCallback(m_glfwWindow, [](GLFWwindow *p_window) {
        Window *window = reinterpret_cast<Window *>(glfwGetWindowUserPointer(p_window));
        if (window == nullptr)
        {
            _ASSERT(0);
        }
        window->SetWindowStatus(WindowStatus::STOPED);
        const Window::CloseCallback *cb = window->GetCloseCallback();
        cb(window);

        glfwDestroyWindow(p_window);
        glfwTerminate();
    });
}

WindowStatus Window::GetWindowStatus()
{
    return m_status;
}

void Window::SetWindowStatus(WindowStatus p_status)
{
    m_status = p_status;
}

const Window::CloseCallback *Window::GetCloseCallback() const
{
    return m_closeCallback;
}

const Window::KeyCallbackFunc *Window::GetKeyCallbackFunc() const
{
    return m_keyCallbackFunc;
}

const Window::MouseCallback *Window::GetMouseCallback() const
{
    return m_mouseCallback;
}

const Window::FramebufferSizeCallback *Window::GetFramebufferSizeCallback() const
{
    return m_framebufferSizeCallback;
}

void Window::Close()
{
    m_status = WindowStatus::STOPED;
}

bool Window::Closed()
{
    return m_status == WindowStatus::STOPED;
}

} // namespace MilkyWay
