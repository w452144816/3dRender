#pragma once
#include "XVertex.h"
#include "XVector.h"
#include "XMatrix.h"

#include "LightHelper.h"

class ShaderBase
{
public:
    ShaderBase();
	virtual ~ShaderBase();

public:
	virtual VertexOut VS(const VertexIn& vin) = 0;	//������ɫ��
    virtual XVector PS(VertexOut& pin) = 0;	//������ɫ��
};

