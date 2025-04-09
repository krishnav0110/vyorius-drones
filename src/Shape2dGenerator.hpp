#ifndef _SHAPE_GENERATOR_H_
#define _SHAPE_GENERATOR_H_

#include <glm/glm.hpp>

#include "graphics/Model.hpp"

class Shape2dGenerator {
public:
    static void generateTriangle(Model &model, float size);
    static void generateRectangle(Model &model, float width, float height);
    static void generateCircle(Model &model, float radius, uint32_t quality);
};

#endif