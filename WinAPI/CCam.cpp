#include "framework.h"
#include "CCam.h"

CCam::CCam()
{
	m_layer = Layer::Cam;
	m_strName = L"Cam";
}

CCam::~CCam()
{
}

void CCam::Init()
{
	pImage = RESOURCE->LoadImg(L"Cam", L"Image\\cam\\cam2.png");
	m_pAnimator = new CAnimator;
	//m_pAnimator->CreateAnimation(L"GreenCam", pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);
	m_pAnimator->CreateAnimation(L"GreenCam", pImage, Vector(0.f, 0.f), Vector(500.f, 280.f), Vector(300.f, 0.f), 0.2f, 1, false);
	//m_pAnimator->CreateAnimation(L"RedCam", pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);
	m_pAnimator->CreateAnimation(L"RedCam", pImage, Vector(600.f, 0.f), Vector(500.f, 280.f), Vector(300.f, 0.f), 0.2f, 1, false);
	
	m_pAnimator->Play(L"GreenCam", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(500, 100), Vector(0, 100));
}

void CCam::Update()
{
	AnimatorUpdate();
}

void CCam::Render()
{
	
}

void CCam::Release()
{
}

void CCam::AnimatorUpdate()
{
	wstring str = L"";
	if (GAME->CamRed)
	{
		str += L"Red";
	}
	else
	{
		str += L"Green";
	}
	str += L"Cam";
	m_pAnimator->Play(str, false);

}

void CCam::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"�÷��̾�")
	{
		GAME->CamRed = true;
	}
}

void CCam::OnCollisionExit(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"�÷��̾�")
	{
		GAME->CamRed = false;
	}
}