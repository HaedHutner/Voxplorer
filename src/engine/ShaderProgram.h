#ifndef VOXPLORER_SHADERPROGRAM_H
#define VOXPLORER_SHADERPROGRAM_H

#include <string>
#include <vector>
#include <fstream>

#include <glad\glad.h>

#include <glm\glm.hpp>
#include <glm\gtc\type_ptr.hpp>

#include "Vertex.hpp"

class ShaderProgram {
private:
    GLuint vertex_shader;
    GLuint fragment_shader;

    GLuint program_id;

    inline static GLuint createShader(const std::string &source, GLenum type);

    ShaderProgram(const std::string &vertexSrc, const std::string &fragmentSrc);

public:

    static ShaderProgram fromSources(const std::string &vertexSrc, const std::string &fragmentSrc);

    static ShaderProgram fromFiles(const std::string &vertexPath, const std::string &fragmentPath);

    void clear();

    void setAttribute(const std::string &name, GLenum type, GLboolean normalized, GLint size, GLsizei stride,
                      const void *pointer) const;

    void setUniformBool(const std::string &name, bool value) const;

    void setUniformInt(const std::string &name, int value) const;

    void setUniformFloat(const std::string &name, float value) const;

    void setUniformDouble(const std::string &name, double value) const;

    void setUniformMat4(const std::string &name, const glm::mat4 &matrix) const;

    void setUniformVec3(const std::string &name, const glm::vec3 &vector) const;

    void setUniformVec4(const std::string &name, const glm::vec4 &vector) const;

    void link();

    void use() const;

    GLuint id() const;
};

#endif