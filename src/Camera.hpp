#ifndef _CAMERA_H_
#define _CAMERA_H_

#include <glm/ext.hpp>

struct Camera {
    float fov;
    float aspect;
    float zNear;
    float zFar;

    Camera(float fov, float aspect, float zNear, float zFar);
    glm::mat4 ProjectionMatrix() const;
};

#endif