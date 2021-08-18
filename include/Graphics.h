//
// Created by Stefan on 08/07/2021.
//
#pragma once

namespace Game
{
    enum GraphicsAPI { NONE, OPENGL, VULKAN };
    extern GraphicsAPI api;

    class Graphics
    {
    public:
        static void Initialize(GraphicsAPI _api);
        static GraphicsAPI GetAPI() { return api; }
        static void Shutdown();
    };
}