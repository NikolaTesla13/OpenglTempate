//
// Created by Stefan on 08/17/2021.
//
#pragma once

namespace Game
{
    struct BufferLayoutElement
    {
        uint32_t type;
        uint32_t count;
        void *offset;
    };

    class BufferLayout
    {
    public:
        BufferLayout()
        {
            stride = 0;
        }

        template <typename T>
        void push(uint32_t count)
        {
            static_assert(false);
        }

        template<>
        void push<float>(uint32_t count)
        {
            layout.push_back({GL_FLOAT, count, (void*)stride});
            stride += count * sizeof(float);
        }

        template<>
        void push<unsigned char>(uint32_t count)
        {
            layout.push_back({GL_UNSIGNED_BYTE, count, (void*)stride});
            stride += count * sizeof(unsigned char);
        }

        template<>
        void push<unsigned int>(uint32_t count)
        {
            layout.push_back({GL_UNSIGNED_INT, count, (void*)stride});
            stride += count * sizeof(unsigned int);
        }

        std::vector<BufferLayoutElement> getLayout() const
        {
            return layout;
        }

        size_t getStride() const
        {
            return stride;
        }

    private:
        std::vector<BufferLayoutElement> layout;
        size_t stride;
    };

    class Buffer
    {
    public:
        explicit Buffer(uint32_t type);
        ~Buffer();

        void bind() const;
        void unbind() const;

        void submitVertices(const std::vector<Vertex> &vertices, uint32_t typeOfDraw) const;
        void submitIndices(const std::vector<uint32_t> &indices, uint32_t typeOfDraw) const;

    private:
        uint32_t id, type;
    };
}