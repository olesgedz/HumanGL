#pragma once

struct Material
{
	float	diffuse[3];
	float	specular[3];
	int		shininess;
};

class Model
{
public:
	Material		material;
	float			*vertices;
	unsigned int	*indices;
	unsigned char	*text_data;
	int				text_width;
	int				text_height;
	unsigned int	vert_number;
	unsigned int	ind_number;
	unsigned int	vbo;
	unsigned int	vao;
	unsigned int	ibo;
	unsigned int	texture;
	int				shader_id;
public:
	int		load_obj(const char* path, bool loadBuf);
	void	vertex_buffer();
	void	set_shader(const char *vPath, const char *fpath);
	void	load_texture(const char *path);
	void	bind_texture();
private:

};
