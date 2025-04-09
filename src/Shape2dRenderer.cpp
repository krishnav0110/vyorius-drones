#include "Shape2dRenderer.hpp"

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "graphics/Renderer.hpp"

void Shape2dRenderer::render(const Shape2d &shape2d, const Texture &texture, const Shader &shader) {
    glm::mat4 transformMatrix = glm::mat4(1.0f);
    transformMatrix = glm::translate(transformMatrix, glm::vec3(shape2d.pos.x, shape2d.pos.y, 0.0));
    transformMatrix = glm::rotate(transformMatrix, glm::radians(shape2d.angle), glm::vec3(0.0, 0.0, 1.0));
    transformMatrix = glm::scale(transformMatrix, glm::vec3(shape2d.scale, shape2d.scale, 1.0));

    shader.SetUniform("transform", transformMatrix);
    Renderer::render(shape2d.model, texture, shader);
}