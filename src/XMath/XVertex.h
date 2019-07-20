#pragma once
#include "XVector.h"


//顶点信息 包括坐标，颜色，纹理坐标，法线等等
class VertexIn
{
public:
	//顶点位置
    XVector pos;
	//顶点颜色
    XVector color;
	//纹理坐标
    XFLOAT2 tex;
	//法线
    XVector normal;

	VertexIn() = default;
    inline VertexIn(XVector pos, XVector color, XFLOAT2 tex, XVector normal)
		:pos(pos), color(color), tex(tex), normal(normal) {}

    inline VertexIn(const VertexIn& rhs):pos(rhs.pos),color(rhs.color),tex(rhs.tex),normal(rhs.normal){}
};

//经过顶点着色器输出的结构
class VertexOut
{
public:
	//世界变换后的坐标
    XVector posTrans;
	//投影变换后的坐标
    XVector posH;
	//纹理坐标
    XFLOAT2 tex;
	//法线
    XVector normal;
	//颜色
    XVector color;
	//1/z用于深度测试
	float oneDivZ;

	VertexOut() = default;
    inline VertexOut(XVector posT, XVector posH, XFLOAT2 tex, XVector normal, XVector color, float oneDivZ)
		:posTrans(posT), posH(posH), tex(tex), normal(normal), color(color), oneDivZ(oneDivZ) {}

    inline VertexOut(const VertexOut& rhs) :posTrans(rhs.posTrans), posH(rhs.posH), tex(rhs.tex), normal(rhs.normal),
	color(rhs.color),oneDivZ(rhs.oneDivZ){}

	VertexOut& operator= (const VertexOut& rhs)
	{
		if (this == &rhs)
			return *this;
		this->normal = rhs.normal;
		this->posH = rhs.posH;
		this->posTrans = rhs.posTrans;
		this->tex = rhs.tex;
		this->color = rhs.color;
		this->oneDivZ = rhs.oneDivZ;
		return *this;
	}
};

