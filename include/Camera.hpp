//
// Created by Oles Gedz on 23/06/2020.
//

#ifndef FT_VOX_SRC_CAMERA_HPP_
#define FT_VOX_SRC_CAMERA_HPP_
#include "Renderer/Entity.hpp"
#include "vox.hpp"
#include "Events.hpp"

class Camera : public Entity {

 public:

  void input(float delta);

};





#endif //FT_VOX_SRC_CAMERA_HPP_
