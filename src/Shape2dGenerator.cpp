#include "Shape2dGenerator.hpp"

#include "util/MathUtil.hpp"

void Shape2dGenerator::generateTriangle(Model &model, float size) {
    std::vector<glm::vec2> positions;
    std::vector<glm::vec2> texCoords;

    positions.emplace_back(glm::vec2{-size, -size});
    positions.emplace_back(glm::vec2{size, -size});
    positions.emplace_back(glm::vec2{0.0f, size});

    texCoords.emplace_back(glm::vec2{0.0f, 0.0f});
    texCoords.emplace_back(glm::vec2{1.0f, 0.0f});
    texCoords.emplace_back(glm::vec2{0.5f, 1.0f});

    model.vao.Bind();
    model.Update((uint32_t)positions.size(), GL_TRIANGLES);
    model.LoadVBO("positions", positions.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), positions.data(), GL_STATIC_DRAW);
    model.LoadVBO("texCoords", texCoords.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);
    model.vao.Unbind();
}

void Shape2dGenerator::generateRectangle(Model &model, float width, float height) {
    std::vector<glm::vec2> positions;
    std::vector<glm::vec2> texCoords;

    positions.emplace_back(glm::vec2{-width, height});
    positions.emplace_back(glm::vec2{width, height});
    positions.emplace_back(glm::vec2{-width, -height});
    positions.emplace_back(glm::vec2{width, -height});

    texCoords.emplace_back(glm::vec2{0.0f, 1.0f});
    texCoords.emplace_back(glm::vec2{1.0f, 1.0f});
    texCoords.emplace_back(glm::vec2{0.0f, 0.0f});
    texCoords.emplace_back(glm::vec2{1.0f, 0.0f});

    model.vao.Bind();
    model.Update((uint32_t)positions.size(), GL_TRIANGLE_STRIP);
    model.LoadVBO("positions", positions.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), positions.data(), GL_STATIC_DRAW);
    model.LoadVBO("texCoords", texCoords.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);
    model.vao.Unbind();
}

void Shape2dGenerator::generateCircle(Model &model, float radius, uint32_t quality) {
    float da = MathUtil::PI_2 / static_cast<float>(quality);

    std::vector<glm::vec2> positions;
    std::vector<glm::vec2> texCoords;
    positions.emplace_back(glm::vec2{0.0f, 0.0f});
    texCoords.emplace_back(glm::vec2{0.5f, 0.5f});

    for (uint32_t i = 0; i <= quality; i++) {
        float angle = da * static_cast<float>(i);
        glm::vec2 point = {radius * std::cosf(angle), radius * std::sinf(angle)};
        positions.emplace_back(point);
        texCoords.emplace_back(glm::vec2(0.5f, 0.5f) + point);
    }

    model.vao.Bind();
    model.Update((uint32_t)positions.size(), GL_TRIANGLE_FAN);
    model.LoadVBO("positions", positions.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), positions.data(), GL_STATIC_DRAW);
    model.LoadVBO("texCoords", texCoords.size() * sizeof(glm::vec2), 2, sizeof(glm::vec2), texCoords.data(), GL_STATIC_DRAW);
    model.vao.Unbind();
}