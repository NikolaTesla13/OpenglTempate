//
// Created by Stefan on 08/17/2021.
//
#pragma once

namespace Game
{
    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void bind() const;
        static void unbind();

        void submitLayout(const BufferLayout& layout);

    private:
        uint32_t id;
    };
}