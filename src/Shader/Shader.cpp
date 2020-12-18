#include "Shader/Shader.hpp"
#include "Shader/ShaderLoader.hpp"
namespace Shader
{
	ShaderProgram::ShaderProgram(const std::string& vertexShaderFile,
					const std::string& fragmentShaderFile)
	: m_programID (loadShader(vertexShaderFile, fragmentShaderFile))
	{

	}
	void ShaderProgram::bind()
	{
		glUseProgram(m_programID);
	}
	void ShaderProgram::unbind()
	{
		glUseProgram(0);
	}
	ShaderProgram::~ShaderProgram()
    {
		glDeleteProgram(m_programID);
    }
	void     ShaderProgram::bindAttribute(GLuint location, const  GLchar * name)
	{
		glBindAttribLocation(m_programID, location, name);
	}

	void ShaderProgram::loadFloat(GLuint location, float value)
	{
	  glUniform1f(location, value);
	}

	void ShaderProgram::loadVector2(GLuint location, const glm::vec2 &value)
	{
	  glUniform2f(location, value.x, value.y);
	}
	void ShaderProgram::loadMatrix4(GLuint location, const glm::mat4 & matrix)
	{
	  glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
	}
	GLuint ShaderProgram::getID() const
	{
	  return m_programID;
	}
}