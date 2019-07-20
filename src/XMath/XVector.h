#pragma once
#include <cmath>
#include "XMatrix.h"

class XVector
{
public:
	float x;
	float y;
	float z;
	float w;	//0�������� 1�����

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
	//��������
	float Length() const;	
	//��һ��
    XVector Normalize();
	//���
    float Dot(XVector v) const;
	//���
    XVector Cross(XVector rhs) const;
	//����== 
    bool operator==(const XVector& rhs) const;
	//��任�������
    XVector operator* (const XMatrix& rhs) const;
    //��XVector�������
    XVector operator* (const XVector& rhs) const;
	//��float���
    XVector operator*(float factor) const;
	//��
    XVector operator+ (const XVector& rhs) const;
	//��
    XVector operator- (const XVector& rhs) const;
	//����
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


//��ά������Ҫ���ڱ�ʾ��������
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
