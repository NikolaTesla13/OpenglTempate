#type vertex
#version 460

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 aColor;

layout (location = 0) out vec3 ourColor;

void main() {
    gl_Position = vec4(aPos, 1.0);
    ourColor = aColor;
}

#type fragment
#version 460

layout (location = 0) in vec3 ourColor;

layout (location = 0) out vec4 fragColor;

void main() {
    fragColor = vec4(ourColor, 1.0);
}