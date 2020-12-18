#include "vox.hpp"
#include "Application.hpp"
#include "Display.hpp"
#include "shader.h"
#include "States/Playing.hpp"
#include "Renderer/Master.hpp"
#include "debugGL.hpp"
Application::Application()
{
  pushState(std::make_unique<State::Playing>(*this));
}

void Application::runMainGameLoop()
{

  	float lastpress = 0;
    while (!glfwWindowShouldClose(Display::getWindow()))
    {

		float now = glfwGetTime();
		float delta = now - lastpress;
		lastpress = now;
        m_renderer.clear();

        m_states.top()->input(camera);

        m_states.top()->update(camera, delta);

        m_states.top()->draw(m_renderer);

        m_renderer.update(camera);


    }
}

void Application::pushState(std::unique_ptr<State::GameState> state)
{
    m_states.push(std::move(state));
} 

void Application::popState()
{
    m_states.pop();
}