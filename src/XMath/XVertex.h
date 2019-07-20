#pragma once
#include "XVector.h"


//������Ϣ �������꣬��ɫ���������꣬���ߵȵ�
class VertexIn
{
public:
	//����λ��
    XVector pos;
	//������ɫ
    XVector color;
	//��������
    XFLOAT2 tex;
	//����
    XVector normal;

	VertexIn() = default;
    inline VertexIn(XVector pos, XVector color, XFLOAT2 tex, XVector normal)
		:pos(pos), color(color), tex(tex), normal(normal) {}

    inline VertexIn(const VertexIn& rhs):pos(rhs.pos),color(rhs.color),tex(rhs.tex),normal(rhs.normal){}
};

//����������ɫ������Ľṹ
class VertexOut
{
public:
	//����任�������
    XVector posTrans;
	//ͶӰ�任�������
    XVector posH;
	//��������
    XFLOAT2 tex;
	//����
    XVector normal;
	//��ɫ
    XVector color;
	//1/z������Ȳ���
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

