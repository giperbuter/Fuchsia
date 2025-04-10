cmake_minimum_required(VERSION 3.15...4.0)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(Fuchsia VERSION 1.0 DESCRIPTION "Vulkan Rendering Engine." LANGUAGES CXX)

set(VULKAN_SDK_ROOT "C:/Include/Vulkan-SDK-1.4.309.0")
set(SDL3_ROOT "C:/Include/x86_64-w64-mingw32")

link_directories(
  "${VULKAN_SDK_ROOT}/Lib"
  "${SDL3_ROOT}/lib"
)

set(SOURCES
  ../src/main.cpp
  ../src/Engine.cpp
)
add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
  "${VULKAN_SDK_ROOT}/Include"
  "${SDL3_ROOT}/include"
)

target_link_libraries(${PROJECT_NAME}
  "libSDL3.dll.a"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)

add_custom_command(TARGET ${PROJECT_NAME} POST_BUILD
  COMMAND ${CMAKE_COMMAND} -E copy_if_different
  "${SDL3_ROOT}/bin/SDL3.dll"
  $<TARGET_FILE_DIR:${PROJECT_NAME}>
)