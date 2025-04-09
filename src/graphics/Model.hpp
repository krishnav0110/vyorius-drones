#ifndef _MODEL_H_
#define _MODEL_H_

#include <string>
#include <vector>
#include <map>
#include "VAO.hpp"

class Model {
private:
    GLuint vaoLayout;
    uint32_t vertexCount;
    GLenum mode;

public:
    VAO vao;
    std::map<std::string, VBO> vbos;

    Model();
    void Update(uint32_t vertexCount);
    void Update(uint32_t vertexCount, GLenum mode);

    void LoadVBO(const std::string &vboName, GLsizeiptr size, GLuint numComponents, GLsizei stride, const void *data, GLenum usage);
    void UpdateVBO(const std::string &vboName, GLsizeiptr size, const void *data);
    void UpdateVBO(const std::string &vboName, GLintptr offset, GLsizeiptr size, const void *data);

    uint32_t GetVertexCount() const;
    GLenum GetMode() const;

    void Delete();
};

#endif