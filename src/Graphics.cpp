//
// Created by Stefan on 08/07/2021.
//
#include <Game.h>
#include <Graphics.h>


namespace Game
{
    GraphicsAPI api;
    void Graphics::Initialize(GraphicsAPI _api)
    {
        api = _api;
        switch (api)
        {
            case GraphicsAPI::OPENGL:
                if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
                {
                    LOG_ERROR("Error initializing glad");
                    Application::Exit(-1);
                }
#ifndef NDEBUG
                LOG_INFO("Vendor:   {0}", glGetString(GL_VENDOR));
                LOG_INFO("Renderer: {0}", glGetString(GL_RENDERER));
                LOG_INFO("Version:  {0}", glGetString(GL_VERSION));
#endif
                break;

            case VULKAN:
                LOG_ERROR("Vulkan not implemented yet!");
                Application::Exit(-1);
                break;

            case NONE:
            default:
                Application::Exit(-1);
                break;
        }
    }

    void Graphics::Shutdown()
    {
        switch (api) {
            case OPENGL:
            case NONE:
            case VULKAN:
                break;
        }
    }
}
