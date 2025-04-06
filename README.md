A lightweight, modular, and flexible Vulkan rendering engine built with SDL3.



Various Instructions:

Adding .cpp files:
Add the path to windows\CMakeLists.txt.
Add the path to android\app\jni\src\Android.mk.
Add the path to macos\CMakeLists.txt.

Windows:
In windows\CMakeLists.txt set the VULKAN_SDK_ROOT and SDL3_ROOT paths.
Make sure the cmake vscode extension sourceDirectory is windows and buildDirectory is windows\bin.
Run with the default vscode build task.

MacOS:
cd ./macos/build
cmake .. -G Xcode -DCMAKE_OSX_SYSROOT=macosx -DCMAKE_OSX_DEPLOYMENT_TARGET=10.15;2D
cmake --build . --config Debug
./Debug/Fuchsia.app/Contents/MacOS/Fuchsia

Android:
Put SDL3 include and src folders and the Android.mk file inside android\app\jni\SDL.
In android\app\jni\src\Android.mk set the LOCAL_C_INCLUDES and LOCAL_SRC_FILES paths. No support to .lib files.
Make sure the ANDROID_HOME(sdk), ANDROID_NDK_HOME(ndk), JAVA_HOME environment variables are correctly set.
Make sure the Path variable includes: %ANDROID_HOME%\platform-tools, %ANDROID_HOME%\cmdline-tools\latest\bin\, and %JAVA_HOME%\bin.
Make sure the sdk, ndk, java, and gradle(inside project) versions are compatible with one another. The sdk will intall the ndk for you.
Connect a phone with Developer Mode on, enabled USB Debugging, accept the USB connection, and authorize to download apps when asked.
Run with: cd android; ./gradlew installDebug; open the app on phone; adb logcat --pid=$(adb shell pidof -s org.libsdl.app);

IOS:
Build the SDL folder using cmake according to SDL3/README/macos online.
cd ios/build
cmake .. -G Xcode -DCMAKE_SYSTEM_NAME=ios -DCMAKE_OSX_SYSROOT=iphoneos -DCMAKE_OSX_DEPLOYMENT_TARGET=13.0 -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="YOUR_TEAM_ID" -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="iPhone Developer"
cmake --build . --config Debug