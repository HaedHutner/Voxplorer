#include "ShaderProgram.h"

inline GLuint ShaderProgram::createShader(const std::string &source, GLenum type) {
    GLint _shader = glCreateShader(type);
    const GLchar *c_source = source.c_str();
    glShaderSource(_shader, 1, &c_source, NULL);
    glCompileShader(_shader);

    GLint success = 0;
    glGetShaderiv(_shader, GL_COMPILE_STATUS, &success);
    if (success == GL_FALSE) {
        GLint len = 0;
        glGetShaderiv(_shader, GL_INFO_LOG_LENGTH, &len);

        char errorLog[2048];
        glGetShaderInfoLog(_shader, len, 0, errorLog);

        printf("%s Shader Compilation Error(%d):\n%s", (type == GL_VERTEX_SHADER) ? "Vertex" : "Fragment", len, errorLog);

        glDeleteShader(_shader);
        return -1;
    }

    return _shader;
}

ShaderProgram::ShaderProgram(const std::string &vertexSrc, const std::string &fragmentSrc) {
    vertex_shader = createShader(vertexSrc, GL_VERTEX_SHADER);
    if (vertex_shader == -1) {
        printf("Vertex Shader Load Failure.\n");
        return;
    }
    fragment_shader = createShader(fragmentSrc, GL_FRAGMENT_SHADER);
    if (fragment_shader == -1) {
        printf("Fragment Shader Load Failure.\n");
        return;
    }

    program_id = glCreateProgram();
    glAttachShader(program_id, vertex_shader);
    glAttachShader(program_id, fragment_shader);
}

ShaderProgram ShaderProgram::fromSources(const std::string &vertexSrc, const std::string &fragmentSrc) {
    return {vertexSrc, fragmentSrc};
}

ShaderProgram ShaderProgram::fromFiles(const std::string &vertexPath, const std::string &fragmentPath) {
    std::ifstream vertexFile{vertexPath};
    std::string vertexContent{std::istreambuf_iterator<char>(vertexFile), std::istreambuf_iterator<char>()};

    std::ifstream fragmentFile{fragmentPath};
    std::string fragmentContent{std::istreambuf_iterator<char>(fragmentFile), std::istreambuf_iterator<char>()};

    ShaderProgram program = ShaderProgram(vertexContent, fragmentContent);

    return program;
}

void ShaderProgram::clear() {
    glDeleteProgram(program_id);
    glDeleteShader(vertex_shader);
    glDeleteShader(fragment_shader);
}

void ShaderProgram::setAttribute(const std::string &name, GLenum type, GLboolean normalized, GLint size, GLsizei stride, const void *pointer) const {
    GLuint attrib = glGetAttribLocation(program_id, name.c_str());
    glEnableVertexAttribArray(attrib);
    glVertexAttribPointer(attrib, size, type, normalized, stride, pointer);
}

void ShaderProgram::setUniformBool(const std::string &name, bool value) const {
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), (int) value);
}

void ShaderProgram::setUniformInt(const std::string &name, int value) const {
    glUniform1i(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::setUniformFloat(const std::string &name, float value) const {
    glUniform1f(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::setUniformDouble(const std::string &name, double value) const {
    glUniform1d(glGetUniformLocation(program_id, name.c_str()), value);
}

void ShaderProgram::setUniformMat4(const std::string &name, const glm::mat4 &matrix) const {
    glUniformMatrix4fv(glGetUniformLocation(program_id, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix));
}

void ShaderProgram::setUniformVec3(const std::string &name, const glm::vec3 &vector) const {
    glUniform3f(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y, vector.z);
}

void ShaderProgram::setUniformVec4(const std::string &name, const glm::vec4 &vector) const {
    glUniform4f(glGetUniformLocation(program_id, name.c_str()), vector.x, vector.y, vector.z, vector.w);
}

void ShaderProgram::link() {
    Vertex::bindAttributes(program_id);

    glLinkProgram(program_id);

    GLint isLinked = 0;
    glGetProgramiv(program_id, GL_LINK_STATUS, &isLinked);
    if (isLinked == GL_FALSE) {
        GLint maxLength = 0;
        glGetProgramiv(program_id, GL_INFO_LOG_LENGTH, &maxLength);

        std::vector<GLchar> infoLog(maxLength);
        glGetProgramInfoLog(program_id, maxLength, &maxLength, &infoLog[0]);

        glDeleteProgram(program_id);

        printf("GLSL Program Link Error: %s", &infoLog[0]);

        return;
    }
}

void ShaderProgram::use() const { glUseProgram(program_id); }

GLuint ShaderProgram::id() const { return program_id; }