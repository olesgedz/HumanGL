#include "Shader/SimpleShader.hpp"
#include "Matrix.hpp"
namespace Shader
{

    SimpleShader::SimpleShader()
    : ShaderProgram("SimpleVertex", "SimpleFragment")
    {
	  getUniformLocations();
	  bind();
	  loadMatrix4(m_locationProjMatrix, Matrix::createProjMatrix());
	  unbind();
    }
    SimpleShader::~SimpleShader()
    {

    }
    void SimpleShader::bindAttributes()
    {
        bindAttribute(0, "inVertexPosition");
    }

	void SimpleShader::setViewMatrix(const glm::mat4  &matrix)
	{
	  loadMatrix4(m_locationViewMatrix, matrix);
	}

	void SimpleShader::setModelMatrix(const glm::mat4  &matrix)
	{
	  loadMatrix4(m_locationModelMatrix, matrix);
	}

	void SimpleShader::setProjMatrix(const glm::mat4  &matrix)
	{
	  loadMatrix4(m_locationProjMatrix, matrix);
	}

void SimpleShader::getUniformLocations()
	{
	  m_locationViewMatrix    = glGetUniformLocation(getID(), "viewMatrix");
	  m_locationModelMatrix   = glGetUniformLocation(getID(), "modelMatrix");
	  m_locationProjMatrix    = glGetUniformLocation(getID(), "projMatrix");
	}
}