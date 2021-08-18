//
// Created by Stefan on 08/05/2021.
//
#include <Game.h>

namespace Game
{
    void Application::Exit(uint32_t code)
    {
        std::exit(code);
    }

    void Application::Initialize()
    {
        Logger::Initialize();
    }

    void Application::Shutdown(int32_t exitCode)
    {
        Logger::Shutdown();
        Graphics::Shutdown();
        std::exit(exitCode);
    }
}