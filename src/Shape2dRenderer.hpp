#ifndef _SHAPE_RENDERER_H_
#define _SHAPE_RENDERER_H_

#include "graphics/Shader.hpp"
#include "graphics/Texture.hpp"

#include "Shape2d.hpp"

class Shape2dRenderer {
public:
    static void render(const Shape2d &shape2d, const Texture &texture, const Shader &shader);
};

#endif