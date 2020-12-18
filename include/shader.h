/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shader.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jblack-b <jblack-b@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/01 03:47:42 by jblack-b          #+#    #+#             */
/*   Updated: 2020/02/29 15:55:14 by jblack-b         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHADER_H
#define SHADER_H
 // include glad to get all the required OpenGL headers
#include "vox.hpp"

using namespace std;
// class Shader
// {
// 	public:
// 		// the program ID
// 		unsigned int ID;
// 		unsigned int Program;
// 		// constructor reads and builds the shader
// 		Shader(const GLchar* vertexPath, const GLchar* fragmentPath)
// 		{
// 			// 1. retrieve the vertex/fragment source code from filePath
// 			std::string vertexCode;
// 			std::string fragmentCode;
// 			std::ifstream vShaderFile;
// 			std::ifstream fShaderFile;
// 			// ensure ifstream objects can throw exceptions:
// 			vShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit); fShaderFile.exceptions (std::ifstream::failbit | std::ifstream::badbit);
// 			try
// 			{
// 				// open files
// 				vShaderFile.open(vertexPath);
// 				fShaderFile.open(fragmentPath);
// 				std::stringstream vShaderStream, fShaderStream;
// 				// read file’s buffer contents into streams
// 				vShaderStream << vShaderFile.rdbuf();
// 				fShaderStream << fShaderFile.rdbuf();
// 				// close file handlers
// 				vShaderFile.close();
// 				fShaderFile.close();
// 				// convert stream into string
// 				vertexCode = vShaderStream.str();
// 				fragmentCode = fShaderStream.str();
// 			}
// 			catch(std::ifstream::failure e)
// 			{
// 				std::cout << "ERROR::SHADER::FILE_NOT_SUCCESFULLY_READ " << vertexPath << std::endl;
// 			}
// 			const char* vShaderCode = vertexCode.c_str();
// 			const char* fShaderCode = fragmentCode.c_str();
// 			// 2. compile shaders
// 			unsigned int vertex, fragment;
// 			int success;
// 			char infoLog[512];
// 			// vertex Shader
// 			vertex = glCreateShader(GL_VERTEX_SHADER);
// 			glShaderSource(vertex, 1, &vShaderCode, NULL);
// 			glCompileShader(vertex);
// 			// print compile errors if any
// 			glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
// 			if(!success)
// 			{
// 				glGetShaderInfoLog(vertex, 512, NULL, infoLog);
// 				std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
// 			};
// 			// fragment Shader
// 			fragment = glCreateShader(GL_FRAGMENT_SHADER);
// 			glShaderSource(fragment, 1, &fShaderCode, NULL);
// 			glCompileShader(fragment);
// 			glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
// 			if(!success)
// 			{
// 				glGetShaderInfoLog(fragment, 512, NULL, infoLog);
// 				std::cout << "ERROR::SHADER::FRAGMET::COMPILATION_FAILED\n" << infoLog << std::endl;
// 			};
// 			this->ID = glCreateProgram();
// 			glAttachShader(this->ID, vertex);
// 			glAttachShader(this->ID, fragment);
// 			glLinkProgram(this->ID);
// 			if(!success)
// 			{
// 				glGetProgramInfoLog(this->ID, 512, NULL, infoLog);
// 				std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
// 			}
// 			// delete the shaders as they’re linked into our program now and no longer necessery
// 			glDeleteShader(vertex);
// 			glDeleteShader(fragment);
// 		}
// 		// use/activate the shader
// 		void use()
// 		{
// 			glUseProgram(ID);
// 		}
// 		// utility uniform functions
// 		void setBool(const std::string &name, bool value) const
// 		{
// 			glUniform1i(glGetUniformLocation(ID, name.c_str()), (int)value);
// 		}
// 		void setInt(const std::string &name, int value) const
// 		{
// 			glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
// 		}
// 		void setFloat(const std::string &name, float value) const
// 		{
// 			glUniform1f(glGetUniformLocation(ID, name.c_str()), value);
// 		}
// 		  // ------------------------------------------------------------------------
// 	void setVec2(const std::string &name, const glm::vec2 &value) const
// 	{ 
// 		glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
// 	}
// 	void setVec2(const std::string &name, float x, float y) const
// 	{ 
// 		glUniform2f(glGetUniformLocation(ID, name.c_str()), x, y); 
// 	}
// 	// ------------------------------------------------------------------------
// 	void setVec3(const std::string &name, const glm::vec3 &value) const
// 	{ 
// 		glUniform3fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
// 	}
// 	void setVec3(const std::string &name, float x, float y, float z) const
// 	{ 
// 		glUniform3f(glGetUniformLocation(ID, name.c_str()), x, y, z); 
// 	}
// 	// ------------------------------------------------------------------------
// 	void setVec4(const std::string &name, const glm::vec4 &value) const
// 	{ 
// 		glUniform4fv(glGetUniformLocation(ID, name.c_str()), 1, &value[0]); 
// 	}
// 	void setVec4(const std::string &name, float x, float y, float z, float w) 
// 	{ 
// 		glUniform4f(glGetUniformLocation(ID, name.c_str()), x, y, z, w); 
// 	}
// 	// ------------------------------------------------------------------------
// 	void setMat2(const std::string &name, const glm::mat2 &mat) const
// 	{
// 		glUniformMatrix2fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
// 	}
// 	// ------------------------------------------------------------------------
// 	void setMat3(const std::string &name, const glm::mat3 &mat) const
// 	{
// 		glUniformMatrix3fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
// 	}
// 	// ------------------------------------------------------------------------
// 	void setMat4(const std::string &name, const glm::mat4 &mat) const
// 	{
// 		glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, &mat[0][0]);
// 	}

// private:
// 	// utility function for checking shader compilation/linking errors.
// 	// ------------------------------------------------------------------------
// 	void checkCompileErrors(GLuint shader, std::string type)
// 	{
// 		GLint success;
// 		GLchar infoLog[1024];
// 		if(type != "PROGRAM")
// 		{
// 			glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
// 			if(!success)
// 			{
// 				glGetShaderInfoLog(shader, 1024, NULL, infoLog);
// 				std::cout << "ERROR::SHADER_COMPILATION_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
// 			}
// 		}
// 		else
// 		{
// 			glGetProgramiv(shader, GL_LINK_STATUS, &success);
// 			if(!success)
// 			{
// 				glGetProgramInfoLog(shader, 1024, NULL, infoLog);
// 				std::cout << "ERROR::PROGRAM_LINKING_ERROR of type: " << type << "\n" << infoLog << "\n -- --------------------------------------------------- -- " << std::endl;
// 			}
// 		}
// 	}
// };

#endif