//
// Created by Stefan on 08/05/2021.
//
#pragma once

namespace Game
{
    class Application
    {
    public:
        static void Initialize();
        static void Exit(uint32_t code);
        static void Shutdown(int32_t exitCode);
    };
}