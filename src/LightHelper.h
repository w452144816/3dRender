#pragma once

#include <windows.h>
#include <algorithm>
#include "XMath.h"

namespace Lights {
	//ƽ�й�
	struct DirectionalLight
	{
		DirectionalLight() { ZeroMemory(this, sizeof(this)); }

        XVector ambient;	//������
        XVector diffuse;	//�������
        XVector specular;	//�߹�
        XVector direction;	//���շ���
	};
	
	//���Դ
	struct PointLight
	{
		PointLight() { ZeroMemory(this, sizeof(this)); }

        XVector ambient;
        XVector diffuse;
        XVector specular;

        XVector position;//��Դλ��

        XVector att;     //˥��ϵ��

		float range;      //���շ�Χ
	};
	//�۹��
	struct SpotLight
	{
		SpotLight() { ZeroMemory(this, sizeof(this)); }

        XVector ambient;
        XVector diffuse;
        XVector specular;

        XVector position;	//����λ��
		
        XVector direction;	//���շ���
		
        XVector att;		//˥��ϵ��
		float range;			//���շ�Χ
		float spot;			//����ǿ��ϵ��   
		
	};
	
	//����
	struct Material
	{
		Material() { ZeroMemory(this, sizeof(this)); }

        XVector ambient;
        XVector diffuse;
        XVector specular;//w��ʾ�߹�ǿ��
        XVector reflect;
	};

	//����ƽ�й�
	inline void ComputeDirectionalLight(
		const Material& mat,				//����
		const DirectionalLight& L,		//ƽ�й�
        XVector normal,					//���㷨��
        XVector toEye,					//���㵽�۾�������
        XVector& ambient,				//������:������
        XVector& diffuse,				//������:�������
        XVector& spec)					//������:�߹�
	{
		// �����ʼ��Ϊ0
        ambient = XVector( 0.0f, 0.0f, 0.0f, 0.0f );
        diffuse = XVector(0.0f, 0.0f, 0.0f, 0.0f);
        spec = XVector(0.0f, 0.0f, 0.0f, 0.0f);

		// ���߷���
        XVector lightVec = -L.direction;
		// ������ֱ�Ӽ���
		ambient = mat.ambient * L.ambient;

		// ����������ϵ��
		//���ߡ����߷����һ��
		lightVec.Normalize();
		float diffuseFactor = lightVec.Dot(normal);

		// ���㱳���Դ���ټ���
		if (diffuseFactor > 0.0f)
		{
			//������߹��ڷ��ߵķ�������
            XVector v = MathUtil::Reflect(-lightVec, normal);

			float specFactor = pow(max(v.Dot(toEye), 0.0f), mat.specular.w);

			//�����������
			diffuse = mat.diffuse * L.diffuse * diffuseFactor;
			//����߹�
			spec = mat.specular * L.specular * specFactor;
		}
	}

	//������Դ
	inline void ComputePointLight(
		const Material& mat,        //����
		PointLight L,				//���Դ
        XVector pos,				//����λ��
        XVector normal,				//���㷨��
        XVector toEye,				//���㵽�۾�������
        XVector& ambient,			//������:������
        XVector& diffuse,			//������:�������
        XVector& spec)				//������:�߹�
	{
        ambient = XVector(0.0f, 0.0f, 0.0f, 0.0f);
        diffuse = XVector(0.0f, 0.0f, 0.0f, 0.0f);
        spec = XVector(0.0f, 0.0f, 0.0f, 0.0f);

		//���շ��򣺶��㵽��Դ
        XVector lightVec = L.position - pos;

		//���㵽��Դ����
		float d = MathUtil::Length(lightVec);

		//������Χ���ټ���
		if (d > L.range)
			return;

		//��һ�����շ���
		lightVec = lightVec * (1.f / d);

		//���㻷����
		ambient = mat.ambient * L.ambient;

		//������ϵ��
		float diffuseFactor = lightVec.Dot(normal);

		if (diffuseFactor > 0.0f)
		{
            XVector v = MathUtil::Reflect(-lightVec, normal);
			float specFactor = pow(max(v.Dot(toEye), 0.0f), mat.specular.w);
			//�����������
			diffuse = mat.diffuse * L.diffuse * diffuseFactor;
			//����߹�
			spec = mat.specular * L.specular * specFactor;
		}

		// ����˥��
        float att = 1.f / L.att.Dot(XVector(1.f, d, d*d));
		diffuse = diffuse * att;
		spec = diffuse * att;
	}

	//����۹��
	inline void  ComputeSpotLight(
		const Material& mat,            //����
		const SpotLight& L,				//�۹��
        XVector pos,					//����λ��
        XVector normal,					//���㷨��
        XVector toEye,					//���㵽�۾�����
        XVector& ambient,				//������:������
        XVector& diffuse,				//������:�������
        XVector& spec)					//������:�߹�
	{
		//��ʼ�����
        ambient = XVector(0.0f, 0.0f, 0.0f, 0.0f);
        diffuse = XVector(0.0f, 0.0f, 0.0f, 0.0f);
        spec = XVector(0.0f, 0.0f, 0.0f, 0.0f);

		//���շ��򣺶��㵽��Դ
        XVector lightVec = L.position - pos;

		//���㵽��Դ����
		float d = MathUtil::Length(lightVec);

		//������ڹ��շ����ټ���
		if (d > L.range)
			return;

		//��һ�����շ���
		lightVec = lightVec * (1.f / d);

		//���㻷����
		ambient = mat.ambient * L.ambient;
		//����������ϵ��
		float diffuseFactor = lightVec.Dot(normal);

		if (diffuseFactor > 0.0f)
		{
            XVector v = MathUtil::Reflect(-lightVec, normal);
			float specFactor = pow(max(v.Dot(toEye), 0.0f), mat.specular.w);
			//�������
			diffuse = mat.diffuse * L.diffuse * diffuseFactor;
			//�߹�
			spec = mat.specular * L.specular * specFactor;
		}

		//�۹�˥��ϵ��
		float spot = pow(max(-lightVec.Dot(L.direction), 0.0f), L.spot);
		//˥��ϵ��
        float att = spot / L.att.Dot(XVector(1.0f, d, d*d));
		ambient = ambient * spot;
		diffuse = diffuse * att;
		spec = spec * att;
	}
}


