#include "SDL.h"
#include <cstdlib>

int main(int argc, char** argv) {
	if(SDL_Init(SDL_INIT_EVENTS | SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to initialize SDL: %s", SDL_GetError());
		return EXIT_FAILURE;
	}
	auto window = SDL_CreateWindow("figdiv", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_ALLOW_HIGHDPI);
	for(auto running = true; running;) {
		SDL_Event event;
		if(!SDL_WaitEvent(&event)) {
			SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Unable to wait for event: %s", SDL_GetError());
			running = false;
			continue;
		}
		switch(event.type) {
		case SDL_QUIT:
			SDL_Log("Quit event");
			running = false;
			break;
		case SDL_WINDOWEVENT:
			switch(event.window.event) {
			case SDL_WINDOWEVENT_CLOSE:
				SDL_Log("Window close event");
				running = false;
				break;
			default:
				SDL_Log("Unhandled window event %d", event.window.event);
				break;
			}
			break;
		default:
			SDL_Log("Unhandled event type %d", event.type);
			break;
		}
	}

	SDL_DestroyWindow(window);
	SDL_Quit();
	return 0;
}
