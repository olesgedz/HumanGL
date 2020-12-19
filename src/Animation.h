//
// Created by Jeromy Black on 12/19/20.
//

#ifndef HUMAGL_ANIMATION_H
#define HUMAGL_ANIMATION_H
#include "glm/glm.hpp"
#include <vector>
#include "AnimationKey.h"
#include "Entity.h"
#include "Maths.h"
class Animation
{
	public:
		Animation(float duration);
	float duration = 0;
	//	Animation(const std::vector<AnimationKey> &keys);

	std::vector<AnimationKey *> keys;
	vec3 GetAnimationTransform(const Entity& entity, float time);
	mat4 GetAnimationMatrix(const Entity& entity, float time);
	vec3 GetRotationMatrix(const Entity& entity, float time);
	private:
		float timeFromStart = 0;

};


#endif //HUMAGL_ANIMATION_H
