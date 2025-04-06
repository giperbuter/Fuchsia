#define VOLK_IMPLEMENTATION
#include <iostream>

#include "engine.h"

int main(int argc, char* argv[]) {
  Engine engine = Engine();

  if (!engine.Initialize()) {
    for (auto error : engine.Errors())
      SDL_LogError(SDL_LOG_CATEGORY_APPLICATION, "%s\n", error.c_str());
  }

  // engine.Tick = [](double) { SDL_Log("Tick!"); };

  engine.Ignite();
  engine.Terminate();
  return 0;
}