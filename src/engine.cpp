#include "engine.h"

void Engine::err(std::string message) {
  errorRegistery.push_back(message);
  Terminate();
}

bool Engine::Initialize() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    err(std::string("Failed to initialize SDL: ") + SDL_GetError());
    return false;
  }

  if (volkInitialize() != VK_SUCCESS) {
    err("Failed to initialize Volk");
    return false;
  }

  window = SDL_CreateWindow("Fuchsia Engine", 800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);

  if (!window) {   
    err(std::string("Failed to create window: ") + SDL_GetError());
    return false;
  }

  if (!SDL_Vulkan_GetInstanceExtensions(nullptr)) {
    err(std::string("Failed to get Vulkan extension count: ") + SDL_GetError());
    return false;
  }
  return true;
}

bool Engine::Ignite() {
  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
        quit = true;
      }
    }
    Tick ? Tick(16) : void();
    SDL_Delay(16);
  }
  return true;
}

bool Engine::Terminate() {
  SDL_DestroyWindow(window);
  SDL_Quit();
  return true;
}

std::vector<std::string> Engine::Errors() { return errorRegistery; }