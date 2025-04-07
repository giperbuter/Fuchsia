#include "engine.h"

void Engine::err(std::string message) {
  std::cerr << message << "\n";
  errorRegistery.push_back(message);
  Terminate();
}

bool Engine::Initialize() {
  if (!SDL_Init(SDL_INIT_VIDEO)) {
    err(std::string("Failed to initialize SDL: ") + SDL_GetError());
    return false;
  }

  if (!SDL_Vulkan_LoadLibrary(nullptr)) {
    err("Failed to load Vulkan library");
    return false;
  }

  if (volkInitialize() != VK_SUCCESS) {
    err(std::string("Failed to initialize Volk: ") + SDL_GetError());
    return false;
  }

  window = SDL_CreateWindow("Fuchsia Engine", 800, 600,
                            SDL_WINDOW_VULKAN | SDL_WINDOW_HIGH_PIXEL_DENSITY);
  if (!window) {
    err(std::string("Failed to create window: ") + SDL_GetError());
    return false;
  }


  VkApplicationInfo appInfo = {};
  appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
  appInfo.pApplicationName = "Fuchsia Engine";
  appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.pEngineName = "Fuchsia";
  appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
  appInfo.apiVersion = VK_MAKE_API_VERSION(0, 1, 2, 0);

  const std::vector<const char*> validationLayers ={};//"VK_LAYER_KHRONOS_validation"}; 
  unsigned int extensionCount = 0; 
  const char* const* extensionNames = SDL_Vulkan_GetInstanceExtensions(&extensionCount); 
  
  VkInstanceCreateInfo createInfo = {};
  createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
  createInfo.flags = VK_INSTANCE_CREATE_ENUMERATE_PORTABILITY_BIT_KHR;
  createInfo.pApplicationInfo = &appInfo;
  createInfo.enabledLayerCount = 0;
  createInfo.ppEnabledLayerNames = validationLayers.data();
  createInfo.enabledExtensionCount = extensionCount;
  createInfo.ppEnabledExtensionNames = extensionNames;

  VkInstance instance;
  VkResult result = vkCreateInstance(&createInfo, nullptr, &instance);
  if (result != VK_SUCCESS) {
    err("Failed to create Vulkan instance: " + std::to_string(result));
    return false;
  }

  volkLoadInstance(instance);


  unsigned int deviceCount = 0;
  VkResult res =
      vkEnumeratePhysicalDeviceGroups(instance, &deviceCount, nullptr);
  if (res != VK_SUCCESS) {
    err("Failed to enumerate physical devices");
    return false;
  }
  SDL_Log("Number of physical devices: %u", deviceCount);

  return true;
}

bool Engine::Ignite() {
  bool quit = false;
  SDL_Event e;
  while (!quit) {
    while (SDL_PollEvent(&e)) {
      if (e.type == SDL_EVENT_QUIT ||
          (e.type == SDL_EVENT_KEY_DOWN && e.key.key == SDLK_ESCAPE)) {
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