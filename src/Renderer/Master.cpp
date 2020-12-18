//
// Created by Oles Gedz on 05/06/2020.
//

#include "Renderer/Master.hpp"
#include "Display.hpp"
namespace Renderer {

  void Master::update(const Camera& camera) {
    m_simpleRenderer.update(camera);
	Display::update();
  }

  void Master::clear() {
	Display::clear();
  }

  void Master::draw(Quad &quad) {
	m_simpleRenderer.draw(quad);
  }
}

