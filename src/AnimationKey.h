//
// Created by Jeromy Black on 12/19/20.
//

#ifndef HUMAGL_ANIMATIONKEY_H
#define HUMAGL_ANIMATIONKEY_H

#include "glm/glm.hpp"
class AnimationKey
{
	public:
	glm::mat4 position;
	glm::mat4 rotation;
	glm::mat4 scale;
	AnimationKey();
	private:
};


#endif //HUMAGL_ANIMATIONKEY_H
