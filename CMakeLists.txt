cmake_minimum_required(VERSION 3.16)
project(OpenglTemplate)

set(BUILD_SHARED_LIBS true)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(OpenglTemplate src/main.cpp vendor/glad/src/glad.c)
include_directories(vendor/glad/include/)

add_subdirectory(vendor/glfw)
target_link_libraries(OpenglTemplate glfw)
include_directories(vendor/glfw/include)

include_directories(vendor/stb)

add_subdirectory(vendor/glm)
target_link_libraries(OpenglTemplate glm)
include_directories(vendor/glm/glm)

add_subdirectory(vendor/spdlog)
target_link_libraries(OpenglTemplate spdlog)
include_directories(vendor/spdlog/include)