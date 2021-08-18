//
// Created by Stefan on 08/07/2021.
//

#pragma once

namespace Game
{
    class Shader
    {
    public:
        Shader() = default;
        explicit Shader(const std::string& vertex_path, const std::string& fragment_path);

        void bind() const;
        uint32_t getId() { return id; }

    private:
        uint32_t id;

        static std::vector<char> readSpirvShader(const std::string& path);
        static void checkCompileErrors(uint32_t shader, const std::string& type);
    };
}