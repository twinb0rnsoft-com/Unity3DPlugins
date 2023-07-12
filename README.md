# Unity3DPlugins
---------
## Screenshot Plugin Documentation
The Screenshot Plugin is a custom plugin for Unity that allows you to capture screenshots of the game view and save them to a specified folder. It integrates with Unity using both C# scripts and a C++ plugin to provide a seamless screenshot capturing experience.

## Features
Capture screenshots of the game view with a simple key press.
Save screenshots to a specified folder within the persistent data path.
Works both in the Unity editor and in standalone game builds.
Uses a C++ plugin for efficient and platform-specific screenshot capturing.

## Requirements
Unity 3D (version 2021.3.16f1 or later)

## Installation
1. To install the Screenshot Plugin in your Unity project, follow these steps:

2. Copy the C++ plugin DLL file (YourPluginName.dll) into your Unity project's "Plugins" folder. Place the DLL in the appropriate platform-specific subfolder (e.g., "x86" or "x86_64") based on your target platform.

3. Create a new C# script in your Unity project and name it ScreenshotCaptureController.cs. Copy the provided C# script code into this file.

4. Attach the ScreenshotCaptureController script to a GameObject in your scene, such as the main camera or an empty GameObject.

## Usage
1. The Screenshot Plugin provides a simple way to capture screenshots during gameplay. Follow these steps to capture a screenshot:

2. Run your Unity project in the Unity editor or build and run the game as a standalone application.

3. During gameplay, press the F5 key (you can modify the key in the Update() method of the ScreenshotCaptureController script) to capture a screenshot of the game view.

4. The screenshot will be saved to a specified folder within the persistent data path. By default, the screenshots are saved in the "Screenshots" folder.

5. To change the folder location or customize the filename format, modify the constants in the ScreenshotCaptureController script. You can specify a different folder path, filename prefix, or file extension to suit your needs.

## Troubleshooting
If you encounter any issues with the Screenshot Plugin, consider the following troubleshooting steps:

1. Ensure that the C++ plugin DLL file is placed in the correct platform-specific folder within the "Plugins" directory.

2. Verify that the C++ plugin code is properly implemented and compatible with Unity. Make sure that the CaptureScreenshot function signature matches the P/Invoke declaration in the C# script.

3. Check that the necessary libraries and dependencies are included and linked correctly in the C++ plugin code.

4. Make sure the folder specified in the ScreenshotCaptureController script has the necessary write permissions for saving the screenshots.

5. Check the Unity console for any error messages or warnings related to the plugin. Enable detailed logging if necessary.

## Limitations
The Screenshot Plugin captures screenshots of the game view only and does not support capturing specific UI elements or overlays but will soon be updated soon. 

The plugin currently supports Windows platforms. If you wish to extend its functionality to other platforms, you'll need to modify and adapt the C++ plugin code accordingly.

## Conclusion
The Screenshot Plugin provides an easy-to-use solution for capturing screenshots during gameplay in Unity. With its seamless integration using both C# scripts and a C++ plugin, you can quickly capture and save screenshots of the game view to enhance your development and debugging process.
