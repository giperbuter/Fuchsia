#define VOLK_IMPLEMENTATION
#include <iostream>

#include "engine.h"

int main(int argc, char* argv[]) {
  Engine engine = Engine();

  if (!engine.Initialize()) return -1;

  // engine.Tick = [](double) { SDL_Log("Tick!"); };

  engine.Ignite();
  engine.Terminate();
  return 0;
}