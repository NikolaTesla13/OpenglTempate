//
// Created by Stefan on 08/17/2021.
//
#include <Game.h>
#include <Buffer.h>


namespace Game
{

    Buffer::Buffer(uint32_t type)
    {
        glGenBuffers(1, &id);
        this->type = type;
    }

    Buffer::~Buffer()
    {
        glDeleteBuffers(1, &id);
    }

    void Buffer::bind() const
    {
        glBindBuffer(type, id);
    }

    void Buffer::unbind() const
    {
        glBindBuffer(type, 0);
    }

    void Buffer::submitVertices(const std::vector<Vertex> &vertices, uint32_t typeOfDraw) const
    {
        if(type == GL_ARRAY_BUFFER)
        {
            bind();
            glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex), vertices.data(), typeOfDraw);
        }
    }

    void Buffer::submitIndices(const std::vector<uint32_t> &indices, uint32_t typeOfDraw) const
    {
        if(type == GL_ELEMENT_ARRAY_BUFFER)
        {
            bind();
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(uint32_t), indices.data(), typeOfDraw);
        }
    }

}
