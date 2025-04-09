#ifndef _RENDERER_H_
#define _RENDERER_H_

#include <glm/glm.hpp>

#include "Model.hpp"
#include "Shader.hpp"
#include "Texture.hpp"

class Renderer {
private:
    static void render(const Model &model);

public:
    static void render(const Model &model, const Shader &shader);
    static void render(const Model &model, const Texture &texture, const Shader &shader);
};

#endif