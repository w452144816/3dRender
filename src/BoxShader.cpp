#include "BoxShader.h"



BoxShader::BoxShader()
{
}


BoxShader::~BoxShader()
{
}

void BoxShader::SetWorldViewProj(const XMatrix &worldViewProj)
{
	m_worldViewProj = worldViewProj;
}

void BoxShader::SetTexture(const XTexture2D& tex)
{
	m_tex = tex;
}

void BoxShader::SetWorld(const XMatrix& world)
{
	m_world = world;
}

void BoxShader::SetWorldInvTranspose(const XMatrix &worldInvTrans)
{
	m_worldInvTranspose = worldInvTrans;
}

void BoxShader::SetEyePos(const XVector& eyePos)
{
	m_eyePos = eyePos;
}

void BoxShader::SetMaterial(const Lights::Material& material)
{
	m_material.ambient = material.ambient;
	m_material.diffuse = material.diffuse;
	m_material.reflect = material.reflect;
	m_material.specular = material.specular;
}

void BoxShader::SetDirLight(const Lights::DirectionalLight& dirLight)
{
	m_dirLight.ambient = dirLight.ambient;
	m_dirLight.diffuse = dirLight.diffuse;
	m_dirLight.direction = dirLight.direction;
	m_dirLight.specular = dirLight.specular;
}

VertexOut BoxShader::VS(const VertexIn& vin)
{
	VertexOut out;
	out.posH = vin.pos * m_worldViewProj;
	
	out.posTrans = vin.pos * m_world;
	out.normal = out.normal * m_worldInvTranspose;

 	out.color = vin.color;
 	out.tex = vin.tex;

	return out;
}

XVector BoxShader::PS(VertexOut& pin)
{
	//��λ������
	pin.normal.Normalize();

	//�������
    XVector texColor = m_tex.Sample(pin.tex);

	//���㵽�۲������
    XVector toEye = (m_eyePos - pin.posTrans).Normalize();

	//��ʼ����ɫֵȫ��Ϊ0
    XVector ambient(0.f, 0.f, 0.f, 0.f);
    XVector diffuse(0.f, 0.f, 0.f, 0.f);
    XVector specular(0.f, 0.f, 0.f, 0.f);

	//��Դ�����õ��Ļ����⡢������ ���߹�
    XVector A, D, S;

	Lights::ComputeDirectionalLight(m_material, m_dirLight, pin.normal, toEye, A, D, S);

	ambient = ambient + A;
	diffuse = diffuse + D;
	specular = specular + S;


	//����+���ռ��㹫ʽ�� ����*(������+�������)+�߹�
    XVector litColor = texColor * (ambient + diffuse) + specular;

	//������ɫ͸����ʹ����������͸����
	litColor.w = m_material.diffuse.w * texColor.w;

	return litColor;
}
