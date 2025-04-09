cmake_minimum_required(VERSION 3.5)

project(vyoriusdrones VERSION 1.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)



find_package(OpenGL REQUIRED)



set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/lib/glew-2.1.0")
set(CMAKE_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/lib/glew-2.1.0/lib/Release/x64/")

find_package(GLEW REQUIRED)
include_directories(${GLEW_INCLUDE_DIRS})
link_libraries(${GLEW_LIBRARIES})



add_subdirectory(src/graphics)
add_subdirectory(src/util)



add_executable(${PROJECT_NAME}
    src/app.cpp
    src/Camera.cpp
    src/Shape2d.cpp
    src/Shape2dGenerator.cpp
    src/Shape2dRenderer.cpp
)

target_compile_options(${PROJECT_NAME} PRIVATE /FS)

target_link_libraries(${PROJECT_NAME}
    OpenGL::GL
    GLEW::GLEW
    krev-graphics
    krev-util
)