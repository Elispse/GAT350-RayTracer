#include "Renderer.h"
#include <iostream>

int main(int args, char* argv[])
{
	std::cout << "Hello, World!";

	// create renderer
	Renderer renderer = Renderer();
	// initialize renderer
	renderer.Initialize();
	// create renderer window with size of 400, 300
	renderer.CreateWindow("New Window", 400, 300);

	bool quit = false;
	while (!quit)
	{
		SDL_Event event;
		SDL_PollEvent(&event);
		switch (event.type)
		{
		case SDL_QUIT:
			quit = true;
			break;
		}
	}

	// shutdown renderer
	renderer.Shutdown();

	return 0;
}