//
// Created by Stefan on 08/05/2021.
//
#pragma once

namespace Game
{
    extern std::shared_ptr<spdlog::logger> Log;

    class Logger
    {
    public:
        static void Initialize();
        static void Shutdown();
    };
}

#ifndef NDEBUG
#define LOG_INFO(...) ::Game::Log->info(__VA_ARGS__)
#define LOG_WARNING(...) ::Game::Log->warn(__VA_ARGS__)
#define LOG_ERROR(...) ::Game::Log->error(__VA_ARGS__)
#else
#define LOG_INFO(...)
#define LOG_WARNING(...)
#define LOG_ERROR(...)
#endif