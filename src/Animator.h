//
// Created by Jeromy Black on 12/19/20.
//

#ifndef HUMAGL_ANIMATOR_H
#define HUMAGL_ANIMATOR_H

#include <vector>
#include "Animation.h"
#include <map>

class Animator
{
	public:
		std::map<int, std::vector<Animation>> animationMap;
		Animator();
		~Animator() = default;
	private:
};


#endif //HUMAGL_ANIMATOR_H
