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
	VertexOut VS(const VertexIn& vin);	//������ɫ��
    XVector PS(VertexOut& pin);

private:
    XMatrix						m_worldViewProj;		//�����ӽ�ͶӰ����
    XTexture2D					m_tex;                  //����
    XMatrix						m_world;				//�������
    XMatrix						m_worldInvTranspose;	//�������������ת�ã����ڵ�������
    Lights::Material			m_material;             //����
    Lights::DirectionalLight	m_dirLight;             //ƽ�й�
    XVector						m_eyePos;               //�۲��
};

