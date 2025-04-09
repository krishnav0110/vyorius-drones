#include "Camera.hpp"

Camera::Camera(float fov, float aspect, float zNear, float zFar) {
    this->fov = fov;
    this->aspect = aspect;
    this->zNear = zNear;
    this->zFar = zFar;
}

glm::mat4 Camera::ProjectionMatrix() const {
    return glm::perspective(fov, aspect, zNear, zFar);
}