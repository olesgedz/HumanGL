#include "render.h"
#include "glad.h"
#include <string>
#include <iostream>

void Render::init()
{
	projection = glm::perspective(glm::radians(60.0f), 640.0f / 480.0f, 0.1f, 100.0f);
	ortProjection = glm::ortho(0.0f, 640.0f, 0.0f, 480.0f);
}

void Render::set_lights_pos(glm::vec3 **lights, int numb)
{
	for (int i = 0; i < numb; ++i)
	{
		light_pos[i].x = lights[i]->x;
		light_pos[i].y = lights[i]->y;
		light_pos[i].z = lights[i]->z;
	}
}

void Render::draw_scene(std::vector<Entity *> scene, glm::vec3** lights, Camera *cam, bool free_cam)
{
	int length = scene.size();
	cam->update_free();

	for (int i = 0; i < length; ++i)
	{
		Entity	*ent = scene[i];
		Model	*mod = ent->mod;
		glUseProgram(mod->shader_id);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, mod->texture);
		glBindVertexArray(mod->vao);

		glm::mat4 model = glm::mat4(1.0f);
		model = glm::translate(model, ent->position);
		model = glm::rotate(model, glm::radians(ent->angle[0]), glm::vec3(1.0f, 0.0f, 0.0f));
		model = glm::rotate(model, glm::radians(ent->angle[1]), glm::vec3(0.0f, 1.0f, 0.0f));
		model = glm::rotate(model, glm::radians(ent->angle[2]), glm::vec3(0.0f, 0.0f, 1.0f));
		model = glm::scale(model, ent->e_scale);

		unsigned int model_loc = glGetUniformLocation(mod->shader_id, "u_M");
		glUniformMatrix4fv(model_loc, 1, GL_FALSE, glm::value_ptr(model));
		unsigned int view_loc = glGetUniformLocation(mod->shader_id, "u_V");
		glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(cam->view));
		unsigned int proj_loc = glGetUniformLocation(mod->shader_id, "u_P");
		glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(projection));

		glUniform1i(glGetUniformLocation(mod->shader_id, "lightNumb"), 3);
		glUniform3fv(glGetUniformLocation(mod->shader_id, "lightPos"), 3, &light_pos[0].x);
		glUniform3f(glGetUniformLocation(mod->shader_id, "viewPos"), cam->pos.x, cam->pos.y, cam->pos.z);
		glUniform1i(glGetUniformLocation(mod->shader_id, "material.diffuse"), 0);
		glUniform3f(glGetUniformLocation(mod->shader_id, "material.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "material.shininess"), 16.0f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.ambient"), 0.3f, 0.3f, 0.3f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.diffuse"), 0.8f, 0.8f, 0.8f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "light.specular"), 0.5f, 0.5f, 0.5f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.constant"), 1.0f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.linear"), 0.045f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "light.quadratic"), 0.0075f);
		glDrawArrays(GL_TRIANGLES, 0, mod->ind_number);
	}
}



void	Render::draw_skybox(Skybox *skybox, Camera* cam)
{
	glDepthMask(GL_FALSE);
	glUseProgram(skybox->shader_id);
	glm::mat4 view = glm::mat4(glm::mat3(cam->view));
	unsigned int view_loc = glGetUniformLocation(skybox->shader_id, "u_V");
	glUniformMatrix4fv(view_loc, 1, GL_FALSE, glm::value_ptr(view));
	unsigned int proj_loc = glGetUniformLocation(skybox->shader_id, "u_P");
	glUniformMatrix4fv(proj_loc, 1, GL_FALSE, glm::value_ptr(projection));
	glBindVertexArray(skybox->vao);
	glBindTexture(GL_TEXTURE_CUBE_MAP, skybox->texture);
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glDepthMask(GL_TRUE);
}
