#include "framework.h"
#include "CSmoke.h"

CSmoke::CSmoke()
{
	m_layer = Layer::Smoke;
	m_strName = L"Smoke";
	m_fTimer = 0.6f;
}

CSmoke::~CSmoke()
{
}

void CSmoke::Init()
{
	pImage = RESOURCE->LoadImg(L"Smoke", L"Image\\Smoke\\Smoking1.png");
	pSound= RESOURCE->LoadSound(L"SmokeSound", L"Sound\\Smoke.wav");
	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"Smokebirth", pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 3, false);

	m_pAnimator->CreateAnimation(L"Smoke", pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 6, true);
	//m_pAnimator->CreateAnimation(L"SmokeDie", pImage, Vector(450.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.2f, 1, false);\


	m_pAnimator->Play(L"Smokebirth", true);


	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(300, 300), Vector(0, 0));
	SOUND->Play(pSound, 0.6f);
}

void CSmoke::Update()
{
	AnimatorUpdate();
	m_fTimer -= DT;
}

void CSmoke::Render()
{
}

void CSmoke::Release()
{
}

void CSmoke::AnimatorUpdate()
{
	wstring str = L"Smoke";
	if (m_fTimer >= 0)
	{
		str += L"birth";
	}
	m_pAnimator->Play(str, false);

}

void CSmoke::OnCollisionEnter(CCollider* pOtherCollider)
{
}

void CSmoke::OnCollisionStay(CCollider* pOtherCollider)
{
}

void CSmoke::OnCollisionExit(CCollider* pOtherCollider)
{
}
