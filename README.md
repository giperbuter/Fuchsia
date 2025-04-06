A lightweight, modular, and flexible Vulkan rendering engine built with SDL2.



Various Instructions:
Adding .cpp files:
Add the path to CMakeLists.txt.
Add the path to android\app\jni\src\Android.mk.

Windows:
In windows/CMakeLists.txt set the VULKAN_SDK_ROOT and SDL3_ROOT paths.
Make sure the cmake vscode extension sourceDirectory is /windows and buildDirectory is /windows/bin.
Run with the default vscode build task.

Android:
Put SDL3 include and src folders and the Android.mk file inside android/app/jni/SDL.
In android\app\jni\src\Android.mk set the LOCAL_C_INCLUDES and LOCAL_SRC_FILES paths. No support to .lib files.
Make sure the ANDROID_HOME(sdk), ANDROID_NDK_HOME(ndk), JAVA_HOME environment variables are correctly set.
Make sure the Path variable includes: %ANDROID_HOME%\platform-tools, %ANDROID_HOME%\cmdline-tools\latest\bin\ and %JAVA_HOME%\bin.
Make sure the sdk, ndk, java and gradle(inside project) versions are compatible with one another.
Run with: cd android; ./gradlew installDebug; open the app on phone; adb shell ps; find the sdl pid; adb logcat --pid={pid}