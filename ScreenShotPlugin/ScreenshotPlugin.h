#pragma once
#ifndef SCREENSHOT_PLUGIN_H
#define SCREENSHOT_PLUGIN_H

#ifdef _WIN32
#define EXPORT_API __declspec(dllexport)
#else
#define EXPORT_API
#endif

extern "C" {
    EXPORT_API void CaptureScreenshot(const char* filename);
}

#endif
