A lightweight, modular, and flexible Vulkan rendering engine built with SDL3.


#### Adding .cpp files
Add the path to windows\CMakeLists.txt.
Add the path to android\app\jni\src\Android.mk.
Add the path to macos\CMakeLists.txt.
#### Windows
1. In windows\CMakeLists.txt set the VULKAN_SDK_ROOT and SDL3_ROOT paths.
2. Make sure the cmake vscode extension sourceDirectory is windows and buildDirectory is windows\bin.
3. Run with the default vscode build task.
#### MacOS
1. Make sure to set the VK_ICD_FILENAMES environment variable to the MoltenVK_icd.json file path.
2. cd ./macos/build
3. cmake .. "-DCMAKE_OSX_ARCHITECTURES=arm64;x86_64" -DCMAKE_OSX_DEPLOYMENT_TARGET=11.0
4. cmake --build . --config Debug
5. ./Fuchsia.app/Contents/MacOS/Fuchsia
#### Android
1. Put SDL3 include and src folders and the Android.mk file inside android\app\jni\SDL.
2. In android\app\jni\src\Android.mk set the LOCAL_C_INCLUDES and LOCAL_SRC_FILES paths. No support to .lib files.
3. Make sure the ANDROID_HOME(sdk), ANDROID_NDK_HOME(ndk), JAVA_HOME environment variables are correctly set.
4. Make sure the Path variable includes: %ANDROID_HOME%\platform-tools, %ANDROID_HOME%\cmdline-tools\latest\bin\, and %JAVA_HOME%\bin.
5. Make sure the sdk, ndk, java, and gradle(inside project) versions are compatible with one another. The sdk will intall the ndk for you.
6. Connect a phone with Developer Mode on, enabled USB Debugging, accept the USB connection, and authorize to download apps when asked.
7. Run with: cd android; ./gradlew installDebug; open the app on phone; adb logcat --pid=$(adb shell pidof -s org.libsdl.app);
#### iOS  *not complete*
1. Build the SDL folder using cmake according to SDL3/README/macos online.
2. cd ios/build
3. cmake .. -G Xcode -DCMAKE_SYSTEM_NAME=ios -DCMAKE_OSX_SYSROOT=iphoneos -DCMAKE_OSX_DEPLOYMENT_TARGET=13.0 -DCMAKE_XCODE_ATTRIBUTE_DEVELOPMENT_TEAM="YOUR_TEAM_ID" 4.4.4.4..
4. -DCMAKE_XCODE_ATTRIBUTE_CODE_SIGN_IDENTITY="iPhone Developer"
5. cmake --build . --config Debug