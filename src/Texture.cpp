#include "Texture.hpp"
#include "stb_image.h"

void BasicTexture::load(const std::string& fileName)
{
    std::string filePath = "../resources/textures/" + fileName + ".png";

    glGenTextures(1, &m_textureID);
    glBindTexture(GL_TEXTURE_2D, m_textureID);
    int width, height, nrChannels;
	
	stbi_set_flip_vertically_on_load(true);
	unsigned char *data = stbi_load(filePath.c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);
	}
	else
	{
		std::runtime_error("Failed to load texture");
	}
	stbi_image_free(data);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    unbind();
}

void BasicTexture::bind()
{
    glBindTexture(GL_TEXTURE_2D, m_textureID);
}

void BasicTexture::unbind()
{
    glBindTexture(GL_TEXTURE_2D, 0);
}