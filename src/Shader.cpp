//
// Created by Stefan on 08/07/2021.
//
#include <Game.h>
#include <Shader.h>


namespace Game
{

    Shader::Shader(const std::string &vertex_path, const std::string &fragment_path)
    {
        std::vector<char> vertexBuffer = readSpirvShader(vertex_path);
        std::vector<char> fragmentBuffer = readSpirvShader(fragment_path);

        uint32_t vertex, fragment;
        int compiled = false;

        id = glCreateProgram();

        vertex = glCreateShader(GL_VERTEX_SHADER);
        glShaderBinary(1, &vertex, GL_SHADER_BINARY_FORMAT_SPIR_V, vertexBuffer.data(), vertexBuffer.size());
        glSpecializeShader(vertex, "main", 0, 0, 0);
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &compiled);
        if (compiled)
            glAttachShader(id, vertex);
        checkCompileErrors(vertex, "VERTEX");

        compiled = true;
        fragment = glCreateShader(GL_FRAGMENT_SHADER);
        glShaderBinary(1, &fragment, GL_SHADER_BINARY_FORMAT_SPIR_V, fragmentBuffer.data(), fragmentBuffer.size());
        glSpecializeShader(fragment, "main", 0, 0, 0);
        glGetShaderiv(fragment, GL_COMPILE_STATUS, &compiled);
        if (compiled)
            glAttachShader(id, fragment);
        checkCompileErrors(fragment, "FRAGMENT");

        glLinkProgram(id);
        checkCompileErrors(id, "PROGRAM");

        glDeleteShader(vertex);
        glDeleteShader(fragment);

    }

    void Shader::bind() const
    {
        glUseProgram(id);
    }

    void Shader::checkCompileErrors(uint32_t shader, const std::string& type)
    {
        int success;
        char infoLog[1024];
        if (type != "PROGRAM")
        {
            glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
            if (!success)
            {
                glGetShaderInfoLog(shader, 1024, nullptr, infoLog);
                LOG_ERROR("Failed the compilation of {0} shader!\n{1}", type, infoLog);
            }
        }
        else
        {
            glGetProgramiv(shader, GL_LINK_STATUS, &success);
            if (!success)
            {
                glGetProgramInfoLog(shader, 1024, nullptr, infoLog);
                LOG_ERROR("Failed the linking of {0} shader!\n{1}", type, infoLog);
            }
        }
    }

    std::vector<char> Shader::readSpirvShader(const std::string &path)
    {
        std::ifstream inStream(path, std::ios::binary);
        std::istreambuf_iterator<char> startIt(inStream), endIt;
        std::vector<char> buffer(startIt, endIt);
        inStream.close();
        return buffer;
    }
}