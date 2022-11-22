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
	pImage = RESOURCE->LoadImg(L"Cam", L"Image\\cam\\cam3.png");
	m_pCamSound= RESOURCE->LoadSound(L"CamSound", L"Sound\\Cam.wav");
	m_pAnimator = new CAnimator;
	//m_pAnimator->CreateAnimation(L"GreenCam", pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);
	m_pAnimator->CreateAnimation(L"GreenCam", pImage, Vector(0.f, 0.f), Vector(500.f, 280.f), Vector(300.f, 0.f), 0.2f, 1, false);
	//m_pAnimator->CreateAnimation(L"RedCam", pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);
	m_pAnimator->CreateAnimation(L"RedCam", pImage, Vector(600.f, 0.f), Vector(500.f, 280.f), Vector(300.f, 0.f), 0.2f, 1, false);
	
	m_pAnimator->Play(L"GreenCam", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(350, 120), Vector(0, 60));
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
	if (pTarget == L"플레이어")
	{
		GAME->CamRed = true;
		SOUND->Play(m_pCamSound, 0.6f);
	}

	if (pTarget == L"Smoke")
	{
		
		GAME->CamRed = false;
		//SOUND->Play(m_pCamSound, 0.6f);
	}
}

void CCam::OnCollisionStay(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"Smoke")
	{

		GAME->CamRed = false;

	}
}

void CCam::OnCollisionExit(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"플레이어")
	{
		GAME->CamRed = false;
		//SOUND->Play(m_pCamSound, 0.6f);
		
	}
}
