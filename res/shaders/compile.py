# python res/shaders/compile.py res/shaders/basic.glsl res/shaders/bin/basic.spv
import os
import sys

if len(sys.argv) < 2:
    print("usage: compile <input> <output>")

glsl_compiler = "glslc"
input = sys.argv[1]
output = sys.argv[2]
input_file = open(input, 'r')
bat_file = open("compile.bat", "a")
lines = input_file.readlines()
current_type = ''
sources = {
    "vertex": "",
    "fragment": "",
}

for line in lines:
    if line.startswith("#type "):
        current_type = line.replace("#type ", "")[:-1]
    else:
        sources[current_type] += line
input_file.close()

for shader in sources:
    temp_file = open(f"temp.{shader}", "w")
    temp_file.write(sources[shader])
    bat_file.write(f"{glsl_compiler} -c -fshader-stage={shader} {temp_file.name} -o {output[:-4]}_{shader}.spv\n") # .temp: error: #version: Desktop shaders for Vulkan SPIR-V require version 140 or higher
    temp_file.close()

os.system("compile.bat")
for shader in sources:
    os.remove(f"temp.{shader}")
