//
// Created by Stefan on 08/05/2021.
//
#include <Game.h>
#include <Logger.h>


namespace Game
{

    std::shared_ptr<spdlog::logger> Log = spdlog::stdout_color_mt("GAME");

    void Logger::Initialize()
    {
        Log->set_pattern("[%^%l%$] %v");
    }

    void Logger::Shutdown()
    {
        Log.reset();
    }
}
