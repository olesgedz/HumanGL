//
// Created by Jeromy Black on 12/19/20.
//

#include "Animation.h"
#include "glad.h"
#include "GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

glm::mat4 Animation::GetAnimationTransform(const Entity& entity, float time)
{
	glm::mat4 ret = glm::mat4(1.0f);
	return glm::rotate(ret, (float)glfwGetTime() * glm::radians(30.0f), glm::vec3 (0, 1, 0));
}

Animation::Animation(const std::vector<AnimationKey> &keys) : keys(keys)
{

}

Animation::Animation(float duration)
{

}
