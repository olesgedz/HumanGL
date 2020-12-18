#include "vox.hpp"
#include "shader.h"
#include "Camera.hpp"
#include "Display.hpp"
using namespace std;
#include "openglInputs.hpp"
#include "Application.hpp"



#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

using namespace glm;

int main(int argc, char **argv)
{

  Display::init();
  Application app;
  app.runMainGameLoop();
	return 0;
}
