#pragma once
#include <windows.h>
#include "XVector.h"


class XTexture2D
{
public:
    XTexture2D() = default;
    XTexture2D(UINT width,UINT height);
    ~XTexture2D();

    XTexture2D(const XTexture2D& rhs) :m_width(rhs.m_width), m_height(rhs.m_height)
	{
		//Éî¿½±´
        m_pixelBuffer = new XVector*[m_width];
		for (int i = 0; i < m_width; ++i)
		{
            m_pixelBuffer[i] = new XVector[m_height];
		}
		for (int i = 0; i < m_width; ++i)
		{
			for (int j = 0; j < m_height; ++j)
			{
				m_pixelBuffer[i][j] = rhs.m_pixelBuffer[i][j];
			}
		}
	}
    XTexture2D& operator=(const XTexture2D& rhs)
	{
		if (this == &rhs)
			return *this;
		m_width = rhs.m_width;
		m_height = rhs.m_height;
        m_pixelBuffer = new XVector*[m_width];
		for (int i = 0; i < m_width; ++i)
		{
            m_pixelBuffer[i] = new XVector[m_height];
		}
		for (int i = 0; i < m_width; ++i)
		{
			for (int j = 0; j < m_height; ++j)
			{
				m_pixelBuffer[i][j] = rhs.m_pixelBuffer[i][j];
			}
		}
		return *this;
	}

public:
    XVector Sample(const XFLOAT2& tex);
public:
	UINT m_width;
	UINT m_height;
    XVector** m_pixelBuffer;
};

