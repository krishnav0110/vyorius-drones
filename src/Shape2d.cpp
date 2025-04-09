#include "Shape2d.hpp"

void Shape2d::IncreaseElevation(const float x) {
    pos.y += x;
}
void Shape2d::DecreaseElevation(const float x) {
    pos.y -= x;
}

void Shape2d::IncreaseRotation(const float x) {
    angle += x;
}
void Shape2d::DecreaseRotation(const float x) {
    angle -= x;
}

void Shape2d::IncreaseScale(const float x) {
    scale += x;
}
void Shape2d::DecreaseScale(const float x) {
    scale -= x;
}