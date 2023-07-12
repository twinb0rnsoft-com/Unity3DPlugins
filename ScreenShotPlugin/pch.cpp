#include "pch.h"
#include "ScreenshotPlugin.h"
#include <Windows.h>
#include <wingdi.h>
#include <stdio.h>

#ifdef __cplusplus
extern "C" {
#endif

    EXPORT_API void CaptureScreenshot(const char* filename)
    {
        HDC hScreenDC = GetDC(NULL);
        HDC hMemoryDC = CreateCompatibleDC(hScreenDC);

        int width = GetDeviceCaps(hScreenDC, HORZRES);
        int height = GetDeviceCaps(hScreenDC, VERTRES);

        HBITMAP hBitmap = CreateCompatibleBitmap(hScreenDC, width, height);

        if (hBitmap != NULL)
        {
            HBITMAP hOldBitmap = (HBITMAP)SelectObject(hMemoryDC, hBitmap);

            BitBlt(hMemoryDC, 0, 0, width, height, hScreenDC, 0, 0, SRCCOPY);

            BITMAPFILEHEADER bfh;
            BITMAPINFOHEADER bi;
            memset(&bfh, 0, sizeof(BITMAPFILEHEADER));
            memset(&bi, 0, sizeof(BITMAPINFOHEADER));
            bi.biSize = sizeof(BITMAPINFOHEADER);
            bi.biWidth = width;
            bi.biHeight = -height; // Negative height to ensure correct orientation
            bi.biPlanes = 1;
            bi.biBitCount = 24; // 24-bit RGB format
            bi.biCompression = BI_RGB;
            bi.biSizeImage = 0;
            bi.biXPelsPerMeter = 0;
            bi.biYPelsPerMeter = 0;
            bi.biClrUsed = 0;
            bi.biClrImportant = 0;

            FILE* file;
            if (fopen_s(&file, filename, "wb") == 0)
            {
                int bfSize = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER) + width * height * 3;
                bfh.bfType = 0x4D42; // "BM" identifier
                bfh.bfSize = bfSize;
                bfh.bfReserved1 = 0;
                bfh.bfReserved2 = 0;
                bfh.bfOffBits = sizeof(BITMAPFILEHEADER) + sizeof(BITMAPINFOHEADER);

                fwrite(&bfh, sizeof(BITMAPFILEHEADER), 1, file);
                fwrite(&bi, sizeof(BITMAPINFOHEADER), 1, file);

                BYTE* pixels = new BYTE[width * height * 3];
                BITMAPINFO bInfo;
                memset(&bInfo, 0, sizeof(BITMAPINFO));
                bInfo.bmiHeader = bi;

                if (GetDIBits(hMemoryDC, hBitmap, 0, height, pixels, &bInfo, DIB_RGB_COLORS))
                {
                    fwrite(pixels, width * height * 3, 1, file);
                }
                delete[] pixels;

                fclose(file);
            }
            else
            {
                // Handle file opening error
                // For debugging purposes, you can output an error message or log the error code
            }

            SelectObject(hMemoryDC, hOldBitmap);
            DeleteObject(hBitmap);
        }

        DeleteDC(hMemoryDC);
        ReleaseDC(NULL, hScreenDC);
    }

#ifdef __cplusplus
}
#endif
