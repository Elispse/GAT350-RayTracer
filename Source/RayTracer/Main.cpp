#include "Renderer.h"
#include "Canvas.h"
#include "Random.h"
#include <iostream>

int main(int args, char* argv[])
{
	std::cout << "Hello, World!";
	seedRandom((unsigned int)time(nullptr));

	// create renderer
	Renderer renderer = Renderer();
	// initialize renderer
	renderer.Initialize();
	// create renderer window with size of 400, 300
	renderer.CreateWindow("New Window", 400, 300);

	Canvas canvas(400, 300, renderer);

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
		case SDL_KEYDOWN:
			switch (event.key.keysym.sym)
			{
			case SDLK_ESCAPE:
				quit = true;
				break;
			}
			break;
		}
		canvas.Clear({ 0, 0, 0, 1 });
		for (int i = 0; i < 1000; i++)
		{
			canvas.DrawPoint({random01() * 400, random01() * 300}, {random01(), random01(), random01(), 1});
		}
		//scene.Render(canvas);
		canvas.Update();
		renderer.PresentCanvas(canvas);
	}
	// shutdown renderer
	renderer.Shutdown();

	return 0;
}