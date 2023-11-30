#include "Renderer.h"
#include "Canvas.h"
#include "Random.h"
#include "Camera.h"
#include "Scene.h"
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
	renderer.CreateWindow("Ray tracer", 400, 300);

	Canvas canvas(400, 300, renderer);

	float aspectRatio = canvas.GetSize().x / (float)canvas.GetSize().y;
	std::shared_ptr<Camera> camera = std::make_shared<Camera>(glm::vec3{ 0, 0, 1 }, glm::vec3{ 0, 0, 0 }, glm::vec3{ 0, 1, 0 }, 70.0f, aspectRatio);

	Scene scene({0, 0, 0}, {1, 1, 1});
	scene.SetCamera(camera);
	
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
		scene.Render(canvas);
		canvas.Update();

		renderer.PresentCanvas(canvas);
	}
	// shutdown renderer
	renderer.Shutdown();

	return 0;
}