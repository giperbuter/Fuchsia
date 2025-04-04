#include <SDL3/SDL.h>
#include <SDL3/SDL_vulkan.h>
#include <Volk/volk.h>

#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

// Error handling helper function
void checkVulkanResult(VkResult result, const char* operation) {
  if (result != VK_SUCCESS) {
    std::cerr << "Vulkan error during " << operation << ": " << result << std::endl;
    throw std::runtime_error("Vulkan operation failed");
  }
}

int main(int argc, char* argv[]) {
  // Initialize SDL
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    std::cerr << "Failed to initialize SDL: " << SDL_GetError() << "\n";
    return 1;
  }

  // Initialize Volk (must be called before any Vulkan functions)
  if (volkInitialize() != VK_SUCCESS) {
    std::cerr << "Failed to initialize Volk\n";
    SDL_Quit();
    return 1;
  }

  // Create SDL window with Vulkan support
  SDL_Window* window = SDL_CreateWindow("Fuchsia Engine", 800, 600, SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  if (!window) {
    std::cerr << "Failed to create window: " << SDL_GetError() << "\n";
    SDL_Quit();
    return 1;
  }

  // Get required Vulkan extensions for SDL
  unsigned int extensionCount = 0;
  if (!SDL_Vulkan_GetInstanceExtensions(&extensionCount)) {
    std::cerr << "Failed to get Vulkan extension count: " << SDL_GetError() << "\n";
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 1;
  }

  // Main loop
  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT || (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
        quit = true;
      }
    }
    SDL_Delay(16);
  }

  // Cleanup
  SDL_DestroyWindow(window);
  SDL_Quit();

  return 0;
}