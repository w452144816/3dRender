#include "XLoadBitmap.h"
#include <Windows.h>
#include <gdiplus.h>

#include <iostream>
#include <fstream>
#include <sstream>

#pragma comment(lib, "gdiplus.lib")
using namespace std;
using namespace Gdiplus;

XTexture2D XMathUtil::LoadBitmapToColorArray(wstring filePath)
{
	GdiplusStartupInput gdiplusstartupinput;
	ULONG_PTR gdiplustoken;
	GdiplusStartup(&gdiplustoken, &gdiplusstartupinput, nullptr);

	Bitmap* bmp = new Bitmap(filePath.c_str());
	if (!bmp)
	{
        //MessageBox(nullptr, "error", "picture path is null!", MB_OK);
		delete bmp;
		GdiplusShutdown(gdiplustoken);
        return XTexture2D(0,0);
	}
	else
	{
		UINT height = bmp->GetHeight();
		UINT width = bmp->GetWidth();
        //≥ı ºªØXTexture2D
        XTexture2D texture(width, height);

		Color color;

		for (int y = 0; y < height; y++)
			for (int x = 0; x < width; x++)
			{
				bmp->GetPixel(x, y, &color);

                texture.m_pixelBuffer[x][height - 1 - y] = XVector(
					color.GetRed() / 255.f,
					color.GetGreen() / 255.f,
					color.GetBlue() / 255.f,
					1.f
				);
			}
		delete bmp;
		GdiplusShutdown(gdiplustoken);
		return texture;
	}
	
}
