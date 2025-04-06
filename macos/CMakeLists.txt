cmake_minimum_required(VERSION 3.15...4.0)
project(Fuchsia VERSION 1.0 DESCRIPTION "Vulkan Rendering Engine." LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(VULKAN_SDK_ROOT "/Library/Vulkan-SDK-1.4.309.0/macOS")
set(SDL3_ROOT "/usr/local")

link_directories(
  "${VULKAN_SDK_ROOT}/Lib"
  "${SDL3_ROOT}/lib"
)

set(SOURCES
  ../src/main.cpp
  ../src/engine.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

target_include_directories(${PROJECT_NAME} PRIVATE
  "${VULKAN_SDK_ROOT}/include"
  "${SDL3_ROOT}/include/SDL3"
)

target_link_libraries(${PROJECT_NAME}
  "libSDL3.dylib"
  "${VULKAN_SDK_ROOT}/lib/libMoltenVK.dylib" #MoltenVK.xcframework/macos-arm64_x86_64/libMoltenVK.a"
)

target_compile_definitions(${PROJECT_NAME} PRIVATE SDL_MAIN_HANDLED)

set_target_properties(Fuchsia PROPERTIES
  MACOSX_BUNDLE YES
  # MACOSX_BUNDLE_INFO_PLIST "${CMAKE_SOURCE_DIR}/macos/Info-MacOS.plist"
)