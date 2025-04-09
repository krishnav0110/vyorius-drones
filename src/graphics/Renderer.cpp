#include <iostream>
#include <GL/glew.h>
#include "Renderer.hpp"

void Renderer::render(const Model &model) {
    model.vao.Bind();
    glDrawArrays(model.GetMode(), 0, model.GetVertexCount());
    model.vao.Unbind();
}

void Renderer::render(const Model &model, const Shader &shader) {
    shader.Bind();
    render(model);
}

void Renderer::render(const Model &model, const Texture &texture, const Shader &shader) {
    shader.Bind();
    texture.Bind();
    render(model);
}