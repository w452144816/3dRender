#pragma once
#include "XVector.h"
#include "XMatrix.h"
#include "XVertex.h"
#include <Windows.h>
#include <cmath>
#include <vector>

namespace MathUtil
{
	extern const float PI;

    //
    inline float POW_F(float x){ return x * x ;}

	//���Բ�ֵ tλ��[0,1]
	float Lerp(float x1, float x2, float t);

	//ʸ����ֵ
    XVector Lerp(const XVector& v1, const XVector& v2, float t);

    //XFLOAT2 ��ֵ
    XFLOAT2 Lerp(const XFLOAT2& v1, const XFLOAT2& v2, float t);

    //XFLOAT3��ֵ
    XFLOAT3 Lerp(const XFLOAT3& v1, const XFLOAT3& v2, float t);

	//VertexOut��ֵ
	VertexOut Lerp(const VertexOut& v1, const VertexOut& v2, float t);

	//clamp
	float Clamp(float x, float min, float max);

	//�Ƕ�ת����
	inline float ZCConvertToRadians(float fDegrees) { return fDegrees * (PI / 180.0f); }

	//��������
    float Length(const XVector& v);

	//��λ����
    XMatrix XMatrixIdentity();

	//����ת��
    XMatrix XMatrixTranspose(const XMatrix& mat);

	//�����Ӧ����ʽ	
    float XMatrixDet(const XMatrix& mat);

	//��������е�ÿһ�� 3*3�����Ӧ������ʽֵ
    float XMatrixAdjElem(
		float a1, float a2, float a3,
		float b1, float b2, float b3,
		float c1, float c2, float c3);

	//������� ��������ʽ��ɵľ����ת��
    XMatrix XMatrixAdj(const XMatrix& mat);

	//����� = �������/(����ʽֵ�ľ���ֵ)
    XMatrix XMatrixInverse(const XMatrix& mat);

	//���ž���
    XMatrix XMatrixScaling(float scaleX, float scaleY, float scaleZ);

	//ƽ�ƾ���
    XMatrix XMatrixTranslate(float offsetX, float offsetY, float offsetZ);

	//��x����ת����
    XMatrix XMatrixRotationX(float angle);

	//��y����ת����
    XMatrix XMatrixRotationY(float angle);

	//��z����ת����
    XMatrix XMatrixRotationZ(float angle);

	//��ȡ�ӽǾ���
    XMatrix XMatrixLookAtLH(XVector eyePos, XVector lookAt, XVector up);

	//��ȡͶӰ���� ͬdx�е�XMMatrixPerspectiveFovLH
	//									    �۲��            ��߱�       ���ü�ƽ��   Զ�ü�ƽ��       
    XMatrix XMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ);
	
	//ͶӰ���������굽��Ļ����任����
    XMatrix XMatrixScreenTransform(int clientWidth, int clientHeight);

    //��ɫXVector(r,b,g,a)ת��ΪUINT
    UINT ColorToUINT(const XVector& color);

	//�������������ڷ��ߵķ�������
    XVector Reflect(const XVector& vin, const XVector& normal);
}
