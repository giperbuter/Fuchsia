cmake_minimum_required(VERSION 3.15...4.0)

project(Fuchsia VERSION 1.0 DESCRIPTION "Vulkan Rendering Engine" LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_COMPILER g++)

set(VULKAN_SDK_ROOT "C:/Include/Vulkan SDK 1.4.309.0")

link_directories(
  "${VULKAN_SDK_ROOT}/Lib"
)

set(SOURCES
  src/main.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})


target_include_directories(${PROJECT_NAME} PRIVATE
  "${VULKAN_SDK_ROOT}/Include"
  # "${VULKAN_SDK_ROOT}/Include/SDL2"
  # "${VULKAN_SDK_ROOT}/Include/glm"
)

target_link_libraries(${PROJECT_NAME}
  "vulkan-1.lib"
  "SDL2.lib"
  "SDL2main.lib"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)


add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${VULKAN_SDK_ROOT}/Bin/SDL2.dll"
  $<TARGET_FILE_DIR:${PROJECT_NAME}>
)