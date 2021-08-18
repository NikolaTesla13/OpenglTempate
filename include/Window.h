//
// Created by Stefan on 08/05/2021.
//
#pragma once

namespace Game
{
    class Window
    {
    public:
        Window(const std::string &title, uint32_t width, uint32_t height);
        ~Window();

        bool shouldClose();
        void beginFrame();

        uint32_t getWidth();
        uint32_t getHeight();
        uint32_t getFramebuffer();

    private:
        GLFWwindow* window;
        uint32_t width, height, framebuffer;
    };
}