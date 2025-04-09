include_directories(${PROJECT_SOURCE_DIR}/lib/stb)

add_library(krev-graphics
    VAO.cpp
    VBO.cpp
    Shader.cpp
    stb_image.cpp
    Texture.cpp
    Model.cpp
    Renderer.cpp
)

set(CMAKE_PREFIX_PATH "${PROJECT_SOURCE_DIR}/lib/SFML-2.6.1")
set(CMAKE_LIBRARY_PATH "${PROJECT_SOURCE_DIR}/lib/SFML-2.6.1/lib/")
find_package(SFML COMPONENTS system window graphics REQUIRED)

target_link_libraries(krev-graphics
sfml-graphics
)

target_include_directories(krev-graphics PUBLIC "${PROJECT_SOURCE_DIR}/lib/glm")

target_include_directories(krev-graphics PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}
)