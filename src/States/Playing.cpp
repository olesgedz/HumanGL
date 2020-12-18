#include "States/Playing.hpp"
#include <iostream>
#include "debugGL.hpp"
#include "Camera.hpp"

namespace State
{
    Playing::Playing(Application& application) 
    : GameState(application)
    {
        m_texture.load("Test");
        m_texture.bind();
        m_shader.getUniformLocations();
	  	m_quad.position.z = -3;
	}

    void Playing::input(Camera& camera)
    {
    }

    void Playing::update(Camera& camera, float delta)
    {
       camera.input(delta);
    }

    void Playing::draw(Renderer::Master &renderer)
	{
		renderer.draw(m_quad);
    }
}