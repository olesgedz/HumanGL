#include "render.h"
#include "glad.h"
#include <string>
#include <iostream>
#include "glm/glm.hpp"

void Render::init()
{
	projection = glm::perspective(glm::radians(60.0f), 1280.0f / 720.0f, 0.1f, 100.0f);
	ortProjection = glm::ortho(0.0f, 1280.0f, 0.0f, 720.0f);
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

void Render::draw_scene(Scene* scene, Camera *cam)
{
	int length = scene->ents.size();

	for (int i = 0; i < length; ++i)
	{
		Entity* ent = scene->ents[i];
		Model	*mod = ent->mod;
		glUseProgram(mod->shader_id);
		//glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, mod->texture);
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
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightPos"), scene->point_lights[0].position.x, scene->point_lights[0].position.y, scene->point_lights[0].position.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "viewPos"), cam->pos.x, cam->pos.y, cam->pos.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "material.diffuse"), ent->color.r, ent->color.g, ent->color.b);
		glUniform3f(glGetUniformLocation(mod->shader_id, "material.specular"), 0.4f, 0.4f, 0.4f);
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

void Render::draw_pbr(Scene* scene, Camera* cam)
{
	int length = scene->ents.size();
	for (int i = 0; i < length; ++i)
	{
		Entity* ent = scene->ents[i];
		Model* mod = ent->mod;
		glUseProgram(mod->shader_id);
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

		glUniform3f(glGetUniformLocation(mod->shader_id, "albedo"), 0.5f, 0.0f, 0.0f);
		glUniform1f(glGetUniformLocation(mod->shader_id, "ao"), 1.0f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "camPos"), cam->pos.x, cam->pos.y, cam->pos.z);
		glUniform1f(glGetUniformLocation(mod->shader_id, "metallic"), 0.9f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "roughness"), 0.9f, 0.05f, 1.0f);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightPositions[0]"), scene->point_lights[0].position.x, scene->point_lights[0].position.y, scene->point_lights[0].position.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightColors[0]"), scene->point_lights[0].color.x, scene->point_lights[0].color.y, scene->point_lights[0].color.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightPositions[1]"), scene->point_lights[1].position.x, scene->point_lights[1].position.y, scene->point_lights[1].position.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightColors[1]"), scene->point_lights[1].color.x, scene->point_lights[1].color.y, scene->point_lights[1].color.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightPositions[2]"), scene->point_lights[2].position.x, scene->point_lights[2].position.y, scene->point_lights[2].position.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightColors[2]"), scene->point_lights[2].color.x, scene->point_lights[2].color.y, scene->point_lights[2].color.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightPositions[3]"), scene->point_lights[3].position.x, scene->point_lights[3].position.y, scene->point_lights[3].position.z);
		glUniform3f(glGetUniformLocation(mod->shader_id, "lightColors[3]"), scene->point_lights[3].color.x, scene->point_lights[3].color.y, scene->point_lights[3].color.z);
		for (int j = 0; j < scene->point_lights.size(); ++j)
		{
			//glUniform3f(glGetUniformLocation(mod->shader_id, ("lightPositions[" + std::to_string(j) + " ]").c_str()), scene->point_lights[j].position.x, scene->point_lights[j].position.y, scene->point_lights[j].position.z);
			//glUniform3f(glGetUniformLocation(mod->shader_id, ("lightColors[" + std::to_string(j) + " ]").c_str()), scene->point_lights[j].color.x, scene->point_lights[j].color.y, scene->point_lights[j].color.z);
		}
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
