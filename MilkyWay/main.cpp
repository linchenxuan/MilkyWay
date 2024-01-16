#include "MilkyWay/Window/Window.h"

#include <iostream>

int main()
{
    MilkyWay::WindowOptions opts{
        "MilkyWay",
        1280,
        1024,
    };

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

    while (!window.Closed())
    {
        window.OnUpdate();
    }
}
