#pragma once
#include <Windows.h>
#include "XVector.h"
#include "XVertex.h"
#include <QDebug>
class Tiny3DDevice
{
public:
	Tiny3DDevice(int width, int height);
	~Tiny3DDevice();
public:
    void DrawPixel(int x, int y, XVector color);
	float GetZ(int x, int y) const;
	void SetZ(int x, int y, float z);
    inline UINT*& GetFrameBuffer() { return m_pFramebuffer; }
	inline int GetClientWidth() { return m_width; }
	inline int getClientHeight() { return m_height; }
    void ClearBuffer(XVector color);
private:
    UINT m_width;
    UINT m_height;
	UINT* m_pFramebuffer;
	float **m_zBuffer;		//z»º´æ
};
