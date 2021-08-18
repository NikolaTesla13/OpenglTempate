//
// Created by Stefan on 08/05/2021.
//
#include <Game.h>

using namespace Game;

int main(int argc, char* argv[])
{
    Application::Initialize();
    Window window("Game", 1280, 720);
    Graphics::Initialize(GraphicsAPI::OPENGL);

    Shader shader("res/shaders/bin/basic_vertex.spv", "res/shaders/bin/basic_fragment.spv");

    std::vector<Vertex> vertices = {
            { {0.5f,  0.5f, 0.0f}, {1.0f, 0.18039215686f, 0.18039215686f, 1.0f}},
            { {0.5f, -0.5f, 0.0f}, {1.0f, 0.96078431372f, 0.23137254902f, 1.0f}},
            { {-0.5f, -0.5f, 0.0f}, {0.23137254902f, 1.0f, 0.26666666666f, 1.0f}},
            { {-0.5f,  0.5f, 0.0f}, {0.07843137254f, 0.35686274509f, 1.0f, 1.0f}},
    };
    std::vector<uint32_t> indices = {
            0, 1, 3,
            1, 2, 3
    };
    Buffer vertexBuffer(GL_ARRAY_BUFFER), indexBuffer(GL_ELEMENT_ARRAY_BUFFER);
    VertexArray vertexArray;

    vertexArray.bind();

    vertexBuffer.bind();
    vertexBuffer.submitVertices(vertices, GL_STATIC_DRAW);

    indexBuffer.bind();
    indexBuffer.submitIndices(indices, GL_STATIC_DRAW);

    BufferLayout bufferLayout;
    bufferLayout.push<float>(3);
    bufferLayout.push<float>(4);
    vertexArray.submitLayout(bufferLayout);

    vertexBuffer.unbind();
    Game::VertexArray::unbind();

    while(!window.shouldClose())
    {
        window.beginFrame();

        shader.bind();
        vertexArray.bind();
        glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, nullptr);
    }

    Application::Shutdown(0);
}