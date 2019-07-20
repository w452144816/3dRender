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

	//线性插值 t位于[0,1]
	float Lerp(float x1, float x2, float t);

	//矢量插值
    XVector Lerp(const XVector& v1, const XVector& v2, float t);

    //XFLOAT2 插值
    XFLOAT2 Lerp(const XFLOAT2& v1, const XFLOAT2& v2, float t);

    //XFLOAT3插值
    XFLOAT3 Lerp(const XFLOAT3& v1, const XFLOAT3& v2, float t);

	//VertexOut插值
	VertexOut Lerp(const VertexOut& v1, const VertexOut& v2, float t);

	//clamp
	float Clamp(float x, float min, float max);

	//角度转弧度
	inline float ZCConvertToRadians(float fDegrees) { return fDegrees * (PI / 180.0f); }

	//向量长度
    float Length(const XVector& v);

	//单位矩阵
    XMatrix XMatrixIdentity();

	//矩阵转置
    XMatrix XMatrixTranspose(const XMatrix& mat);

	//矩阵对应行列式	
    float XMatrixDet(const XMatrix& mat);

	//伴随矩阵中的每一项 3*3矩阵对应的行列式值
    float XMatrixAdjElem(
		float a1, float a2, float a3,
		float b1, float b2, float b3,
		float c1, float c2, float c3);

	//伴随矩阵 代数余子式组成的矩阵的转置
    XMatrix XMatrixAdj(const XMatrix& mat);

	//逆矩阵 = 伴随矩阵/(行列式值的绝对值)
    XMatrix XMatrixInverse(const XMatrix& mat);

	//缩放矩阵
    XMatrix XMatrixScaling(float scaleX, float scaleY, float scaleZ);

	//平移矩阵
    XMatrix XMatrixTranslate(float offsetX, float offsetY, float offsetZ);

	//绕x轴旋转矩阵
    XMatrix XMatrixRotationX(float angle);

	//绕y轴旋转矩阵
    XMatrix XMatrixRotationY(float angle);

	//绕z轴旋转矩阵
    XMatrix XMatrixRotationZ(float angle);

	//获取视角矩阵
    XMatrix XMatrixLookAtLH(XVector eyePos, XVector lookAt, XVector up);

	//获取投影矩阵 同dx中的XMMatrixPerspectiveFovLH
	//									    观察角            宽高比       近裁剪平面   远裁剪平面       
    XMatrix XMatrixPerspectiveFovLH(float fovAngleY, float aspectRatio, float nearZ, float farZ);
	
	//投影出来的坐标到屏幕坐标变换矩阵
    XMatrix XMatrixScreenTransform(int clientWidth, int clientHeight);

    //颜色XVector(r,b,g,a)转化为UINT
    UINT ColorToUINT(const XVector& color);

	//求入射向量关于法线的反射向量
    XVector Reflect(const XVector& vin, const XVector& normal);
}
