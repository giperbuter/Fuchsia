#include <iostream>

#include "engine.h"

int main(int argc, char* argv[]) {
  Engine engine = Engine();

  if (!engine.Initialize()) {
    for (auto error : engine.Errors())
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "SDL_Init failed (%s)", SDL_GetError());
  }

  engine.Tick = [](double) { SDL_Log("Tick!"); };

  engine.Ignite();
  engine.Terminate();
  return 0;
}