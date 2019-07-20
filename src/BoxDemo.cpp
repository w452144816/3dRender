#include "BoxDemo.h"
#include "BoxShader.h"

#include <vector>
BoxDemo::BoxDemo():m_theta(0.0f * MathUtil::PI),m_phi(1.0f*MathUtil::PI),m_radius(50.0f)
{	
	m_lastMousePos.x = 0;
	m_lastMousePos.y = 0;

    m_world = MathUtil::XMatrixIdentity();

	//ƽ�й�
    m_dirLight.ambient = XVector(0.2f, 0.2f, 0.2f, 1.0f);
    m_dirLight.diffuse = XVector(0.5f, 0.5f, 0.5f, 1.0f);
    m_dirLight.specular = XVector(0.5f, 0.5f, 0.5f, 1.0f);
    m_dirLight.direction = XVector(0.57735f, 0.57735f, 0.57735f);

	//����
    m_material.ambient = XVector(0.7f, 0.85f, 0.7f, 1.0f);
    m_material.diffuse = XVector(0.7f, 0.85f, 0.7f, 1.0f);
    m_material.specular = XVector(0.8f, 0.8f, 0.8f, 16.0f);
}


BoxDemo::~BoxDemo()
{
	Clear();
}

bool BoxDemo::Init(HINSTANCE hInstance,HWND hWnd)
{	
	m_hWnd = hWnd;
	m_hInstance = hInstance;
	RECT rc;
	GetClientRect(m_hWnd, &rc);
	m_width = rc.right - rc.left;
	m_height = rc.bottom - rc.top;

	m_pDevice = new Tiny3DDevice(m_width, m_height);	
	m_pImmediateContext = new Tiny3DDeviceContext();
	m_pImmediateContext->Init(m_pDevice);
	m_pShader = new BoxShader();

	//�������㻺��	
    GeometryGenerator::GetInstance()->CreateBox(20.f, 10.f, 2.f, m_box);
    m_vertices.resize(m_box.vertices.size());
    for (UINT i = 0; i < m_box.vertices.size(); ++i)
    {
        m_vertices[i].pos = m_box.vertices[i].pos;
        m_vertices[i].tex = m_box.vertices[i].tex;
        m_vertices[i].normal = m_box.vertices[i].normal;
        m_vertices[i].color = m_box.vertices[i].color;
	}

	m_pImmediateContext->SetVertexBuffer(m_vertices);	

	//������������
	//create index buffer
    m_indices.resize(m_box.indices.size());

    for (UINT i = 0; i < m_box.indices.size(); ++i)
	{
        m_indices[i] = m_box.indices[i];
	}

	m_pImmediateContext->SetIndexBuffer(m_indices);

	//������ɫ��
	m_pImmediateContext->SetShader(m_pShader);

	//��������
    m_tex = XMathUtil::LoadBitmapToColorArray(L"C:/work/VS/w3dRender/src/Texture/Wood.bmp");

	//������ɫ������
	//�����������һ�β��ڸı䣬�ʲ�����Update������
	m_pShader->SetTexture(m_tex);

	//������ɫ����Դ������
	m_pShader->SetDirLight(m_dirLight);
	m_pShader->SetMaterial(m_material);
	
	return true;
}

void BoxDemo::Update(float dt)
{
	
	float x = m_radius * sinf(m_phi) * cosf(m_theta);
    float y = m_radius * sinf(m_phi) * sinf(m_theta);
    float z = m_radius * cosf(m_phi);

    XVector pos(x, y, z, 1.f);
    XVector target(0.f, 0.f, -50.f, 1.f);
    XVector up(0.f, 1.f, 0.f, 0.f);

    XMatrix view = MathUtil::XMatrixLookAtLH(pos, target, up);
    XMatrix proj = MathUtil::XMatrixPerspectiveFovLH(MathUtil::PI / 4, m_pDevice->GetClientWidth() /
        static_cast<float>(m_pDevice->getClientHeight()), 1.f, 1000.f);

    XMatrix world = MathUtil::XMatrixIdentity();
	m_worldViewProj = world*view*proj;
	m_world = world;

	//����������ת��
    m_worldInvTranspose = MathUtil::XMatrixTranspose(MathUtil::XMatrixInverse(world));

	//�������λ�� �Ա㱳������
	m_pImmediateContext->SetCameraPos(pos);
	
	//������ɫ����eyePos
	m_pShader->SetEyePos(pos);
}

void BoxDemo::Render()
{
	//��պ󻺳�ͼƬ
    m_pDevice->ClearBuffer(XVector(0.75f, 0.75f, 0.75f,1.f));

	//������Ⱦ״̬
	m_pImmediateContext->SetRenderMode(TINY3D_FILL_SOLIDE);
	//������ɫ������
	m_pShader->SetWorldViewProj(m_worldViewProj);
	m_pShader->SetWorld(m_world);
	m_pShader->SetWorldInvTranspose(m_worldInvTranspose);

	m_pImmediateContext->DrawIndexed(m_indices.size(), 0, 0);
}

void BoxDemo::Clear()
{
	if(m_pDevice)
		delete m_pDevice;
	if(m_pImmediateContext)
		delete m_pImmediateContext;
	if (m_pShader)
		delete m_pShader;
}

void BoxDemo::OnMouseDown(WPARAM btnState, int x, int y)
{
    m_lastMousePos.x = x;
    m_lastMousePos.y = y;
    SetCapture(m_hWnd);
}

void BoxDemo::OnMouseUp(WPARAM btnState, int x, int y)
{
    ReleaseCapture();
}

void BoxDemo::OnMouseMove(WPARAM btnState, int x, int y)
{
    //if ((btnState & MK_LBUTTON) != 0)
    {
        //�Ƕ�ת����
/*        float dx = MathUtil::ZCConvertToRadians(0.25f*static_cast<float>(x - m_lastMousePos.x));
        float dy = MathUtil::ZCConvertToRadians(0.25f*static_cast<float>(y - m_lastMousePos.y))*/;

        float dx = MathUtil::ZCConvertToRadians(0.25f*static_cast<float>(x));
        float dy = MathUtil::ZCConvertToRadians(0.25f*static_cast<float>(y));


        m_theta -= dx;
        m_phi += dy;

        m_phi = MathUtil::Clamp(m_phi, 0.1f, MathUtil::PI - 0.1f);
    }
    //else if ((btnState & MK_RBUTTON) != 0)
    {
//        float dx = 0.2f*static_cast<float>(x - m_lastMousePos.x);
//        float dy = 0.2f*static_cast<float>(y - m_lastMousePos.y);

//        float dx = 0.01f*static_cast<float>(x);
//        float dy = 0.01f*static_cast<float>(y);

//        m_radius += dx - dy;

//        m_radius = MathUtil::Clamp(m_radius, 3.0f, 300.0f);
    }

    m_lastMousePos.x = x;
    m_lastMousePos.y = y;
}

void BoxDemo::Strafe(WPARAM btnState, int d)
{
    float dd = 0.01f*static_cast<float>(d);
    XVector theCurrentPos = getPos();
    XVector  thePosition = mRight * d + getPos();
    setPos(thePosition);
    XVector theCurrentPos1 = getPos();
    bool a = true;
    bool b = a;
}

void BoxDemo::Walk(WPARAM btnState, int d)
{
    float dd = 0.01f*static_cast<float>(d);
    XVector theCurrentPos = getPos();
    XVector  thePosition = mLook * d + getPos();
    setPos(thePosition);
    XVector theCurrentPos1 = getPos();
    bool a = true;
    bool b = a;
}

XVector BoxDemo::getPos()
{
    float x = abs(m_radius * sinf(m_phi) * cosf(m_theta)) < 0.01f ? 0 : m_radius * sinf(m_phi) * cosf(m_theta);
    float y = abs(m_radius * sinf(m_phi) * sinf(m_theta)) < 0.01f ? 0 : m_radius * sinf(m_phi) * sinf(m_theta);
    float z = m_radius * cosf(m_phi);

    return XVector(x, y, z, 1.f);
}

void BoxDemo::setPos(XVector pos)
{
    //m_phiҲ���Ǧȣ��ͣ�+Z�ᣩ�Ƕȣ���Χ0-180�㣻
    //m_thetaҲ���Ǧգ��ͣ�+X����Ƕȣ���Χ0-360�㣻
    m_radius = pos.Length();
    m_phi = isnan(acosf(pos.z / m_radius)) ? 0 : acosf(pos.z / m_radius);
    m_theta = isnan(atanf(pos.y / pos.x)) ? 0 : atanf(pos.y / pos.x);
//    if (-0.0f == m_theta)
//        m_theta = MathUtil::PI;
}


