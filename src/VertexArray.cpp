//
// Created by Stefan on 08/17/2021.
//
#include <Game.h>
#include <VertexArray.h>


namespace Game
{

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &id);
    }

    VertexArray::~VertexArray()
    {
        glDeleteVertexArrays(1, &id);
    }

    void VertexArray::bind() const
    {
        glBindVertexArray(id);
    }

    void VertexArray::unbind()
    {
        glBindVertexArray(0);
    }

    void VertexArray::submitLayout(const BufferLayout& layout)
    {
        std::vector<BufferLayoutElement> _layout = layout.getLayout();
        uint32_t count = 0;
        for(BufferLayoutElement element: _layout)
        {
            glVertexAttribPointer(count, element.count, element.type, GL_FALSE, layout.getStride(), element.offset);
            glEnableVertexAttribArray(count);
            count++;
        }
    }

}
