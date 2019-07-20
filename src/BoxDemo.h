#pragma once
#include "Tiny3D.h"
#include "BoxShader.h"
#include "XMath.h"
#include "GeometryGenerator.h"

class BoxDemo
{
public:
	BoxDemo();
	~BoxDemo();
public:
	bool Init(HINSTANCE hInstance, HWND hWnd);
	void Update(float dt);
	void Render();
	void Clear();	

	//����¼�����
    void OnMouseDown(WPARAM btnState, int x, int y);
    void OnMouseUp(WPARAM btnState, int x, int y);
    void OnMouseMove(WPARAM btnState, int x, int y);

    void Strafe(WPARAM btnState, int d);
    void Walk(WPARAM btnState, int d);

private:
    XVector   getPos();
    void      setPos(XVector pos);
public:
	inline Tiny3DDevice*& GetDevice() { return m_pDevice; }
private:
	int							m_width, m_height;
	HINSTANCE					m_hInstance;
	HWND							m_hWnd;

	Tiny3DDevice*				m_pDevice;
	Tiny3DDeviceContext*			m_pImmediateContext;
	BoxShader*					m_pShader;

    XMatrix						m_worldViewProj;			//�����ӽ�ͶӰ����
    XMatrix						m_world;					//����任����
    XMatrix						m_worldInvTranspose;		//����任������ת�� ���ڵ�������

	std::vector<VertexIn>		m_vertices;				//���㻺��
	std::vector<UINT>			m_indices;				//��������

	GeometryGenerator::MeshData	m_box;

    XTexture2D					m_tex;					//����

	Lights::Material				m_material;				//����
	Lights::DirectionalLight		m_dirLight;				//ƽ�й�Դ

	//���������λ�ýǶȵ�
	float						m_theta;
	float						m_phi;
	float						m_radius;
	POINT						m_lastMousePos;

    XVector                     mRight = { 1.0f, 0.0f, 0.0f };
    XVector                     mUp = { 0.0f, 1.0f, 0.0f };
    XVector                     mLook = { 0.0f, 0.0f, 5.0f, 1.0f};
};

