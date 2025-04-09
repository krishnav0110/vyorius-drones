#ifndef _SHADER_H_
#define _SHADER_H_

#include <string>

#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
private:
    void Compile(const char* vertexCode, const char* fragmentCode);
    void CheckCompileErrors(const GLuint shaderID, const std::string &type) const;

public:
    GLuint ID;
    void LoadFromFile(const std::string &vertexPath, const std::string &fragmentPath);

    void Bind() const;
    void Unbind() const;

    void SetUniform(const std::string &name, const glm::mat4 &value) const;  
    void SetUniform(const std::string &name, GLuint value) const;  
};

#endif