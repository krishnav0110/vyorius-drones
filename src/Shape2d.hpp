#ifndef _SHAPE_H_
#define _SHAPE_H_

#include <glm/glm.hpp>

#include "graphics/Model.hpp"

struct Shape2d {
    glm::vec2 pos = {0.0f, 0.0f};
    float angle = 0.0f;
    float scale = 1.0f;

    Model model;

    void IncreaseElevation(const float x);
    void DecreaseElevation(const float x);

    void IncreaseRotation(const float x);
    void DecreaseRotation(const float x);

    void IncreaseScale(const float x);
    void DecreaseScale(const float x);
};

#endif