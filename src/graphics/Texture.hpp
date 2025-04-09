#ifndef _TEXTURE_H_
#define _TEXTURE_H_

#include <string>

#include <GL/glew.h>

class Texture {
public:
    GLuint ID;
    Texture(const std::string &path);

    void Bind() const;
    void Unbind() const;
};

#endif