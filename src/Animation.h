//
// Created by Jeromy Black on 12/19/20.
//

#ifndef HUMAGL_ANIMATION_H
#define HUMAGL_ANIMATION_H
#include "glm/glm.hpp"
#include "AnimationKey.h"
#include <vector>
#include "Entity.h"
class Animation
{
	public:
		Animation(float duration);
		Animation(const std::vector<AnimationKey> &keys);

	std::vector<AnimationKey> keys;
	glm::mat4 GetAnimationTransform(const Entity& entity, float time);
	private:
		float timeFromStart = 0;
		float duration = 0;
};


#endif //HUMAGL_ANIMATION_H
