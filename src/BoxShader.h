#pragma once
#include "ShaderBase.h"
#include "XMath.h"

class BoxShader : public ShaderBase
{
public:
	BoxShader();
	~BoxShader();

public:
    void SetWorldViewProj(const XMatrix& worldViewProj);
    void SetTexture(const XTexture2D& tex);
    void SetWorld(const XMatrix& world);
    void SetWorldInvTranspose(const XMatrix& worldInvTrans);
    void SetEyePos(const XVector &eyePos);
	void SetMaterial(const Lights::Material& material);
	void SetDirLight(const Lights::DirectionalLight& dirLight);
public:
	VertexOut VS(const VertexIn& vin);	//顶点着色器
    XVector PS(VertexOut& pin);

private:
    XMatrix						m_worldViewProj;		//世界视角投影矩阵
    XTexture2D					m_tex;                  //纹理
    XMatrix						m_world;				//世界矩阵
    XMatrix						m_worldInvTranspose;	//世界矩阵逆矩阵的转置，用于调整法线
    Lights::Material			m_material;             //材质
    Lights::DirectionalLight	m_dirLight;             //平行光
    XVector						m_eyePos;               //观察点
};

