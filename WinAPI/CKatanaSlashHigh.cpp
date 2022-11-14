#include "framework.h"
#include "CKatanaSlashHigh.h"

CKatanaSlashHigh::CKatanaSlashHigh()
{
	m_layer = Layer::Missile;
	m_strName = L"KatanaSlashHigh";
	m_pTimer = 0;
}

CKatanaSlashHigh::~CKatanaSlashHigh()
{
}

void CKatanaSlashHigh::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KatanaSlashHigh", L"Image\\KatanaSlash_high.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"KatanaSlashHighRight", m_pImage, Vector(0.f, 0.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.07f, 5, false);
	m_pAnimator->CreateAnimation(L"KatanaSlashHighLeft", m_pImage, Vector(0.f, 300.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.07f, 5, false);



	if (GAME->RightAttack == true)
	{
		m_pAnimator->Play(L"KatanaSlashHighRight", true);
	}
	else
	{
		m_pAnimator->Play(L"KatanaSlashHighLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
}

void CKatanaSlashHigh::Update()
{
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
	AnimatorUpdate();
}

void CKatanaSlashHigh::Render()
{
}

void CKatanaSlashHigh::Release()
{
}

void CKatanaSlashHigh::AnimatorUpdate()
{
	wstring str = L"KatanaSlashHigh";

	if (GAME->RightAttack == true)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}
	m_pAnimator->Play(str, false);
}

void CKatanaSlashHigh::OnCollisionEnter(CCollider* pOtherCollider)
{
}
