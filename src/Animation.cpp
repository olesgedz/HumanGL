//
// Created by Jeromy Black on 12/19/20.
//

#include "Animation.h"
#include "glad.h"
#include "GLFW/glfw3.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Maths.h"

mat4 Animation::GetAnimationTransform(const Entity& entity, float time)
{
	mat4 ret = mat4(1.0f);
	return rotate(ret, vec3(0, (float)glfwGetTime() * 30, 0));
}

Animation::Animation(const std::vector<AnimationKey> &keys) : keys(keys)
{

}

Animation::Animation(float duration)
{

}
