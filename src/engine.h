#pragma once
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>
#include <SDL3/SDL_vulkan.h>
#include <Volk/volk.h>

#include <functional>
#include <memory>
#include <string>
#include <vector>

class Engine {
 private:
  SDL_Window* window;
  std::vector<std::string> errorRegistery = std::vector<std::string>();
  void err(std::string message);

 public:
  bool Initialize();
  bool Ignite();
  bool Terminate();
  std::function<void(double)> Tick;
  std::vector<std::string> Errors();
};