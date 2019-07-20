#pragma once
#include <cmath>
#include "XMatrix.h"

class XVector
{
public:
	float x;
	float y;
	float z;
	float w;	//0代表向量 1代表点

public:
    XVector() = default;
    inline XVector(float x1, float y1, float z1, float w1 = 0) :x(x1), y(y1), z(z1), w(w1) {}
    inline XVector(const XVector& rhs) :x(rhs.x), y(rhs.y), z(rhs.z), w(rhs.w) {}
    inline XVector& operator= (const XVector& rhs)
	{
		if (this == &rhs)
			return *this;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		w = rhs.w;
		return *this;
	}

public:
	//向量长度
	float Length() const;	
	//归一化
    XVector Normalize();
	//点乘
    float Dot(XVector v) const;
	//叉乘
    XVector Cross(XVector rhs) const;
	//重载== 
    bool operator==(const XVector& rhs) const;
	//与变换矩阵相乘
    XVector operator* (const XMatrix& rhs) const;
    //与XVector分量相乘
    XVector operator* (const XVector& rhs) const;
	//与float相乘
    XVector operator*(float factor) const;
	//加
    XVector operator+ (const XVector& rhs) const;
	//减
    XVector operator- (const XVector& rhs) const;
	//负号
    XVector operator-() const;
	
};


class XFLOAT3
{
public:
	float x;
	float y;
	float z;
public:
    XFLOAT3() = default;
    inline XFLOAT3(float r,float b,float g):x(r),y(b),z(g){}
    inline XFLOAT3(const XFLOAT3& rhs) :x(rhs.x), y(rhs.y), z(rhs.z) {}
    inline XFLOAT3& operator= (const XFLOAT3& rhs)
	{
		if (this == &rhs)
			return *this;
		x = rhs.x;
		y = rhs.y;
		z = rhs.z;
		return *this;
	}
};


//二维向量主要用于表示纹理坐标
class XFLOAT2
{
public:
	float u;
	float v;
public:
    XFLOAT2() = default;
    inline XFLOAT2(float x, float y) :u(x), v(y) {}
    inline XFLOAT2(const XFLOAT2& rhs):u(rhs.u),v(rhs.v){}
    inline XFLOAT2& operator= (const XFLOAT2& rhs)
	{
		if (this == &rhs)
			return *this;
		u = rhs.u;
		v = rhs.v;
		return *this;
	}
};
