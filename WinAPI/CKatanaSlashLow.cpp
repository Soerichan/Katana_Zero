#include "framework.h"
#include "CKatanaSlashLow.h"

CKatanaSlashLow::CKatanaSlashLow()
{
	m_layer = Layer::Missile;
	m_strName = L"KatanaSlashLow";
	m_pTimer = 0;
}

CKatanaSlashLow::~CKatanaSlashLow()
{
}

void CKatanaSlashLow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KatanaSlashlow", L"Image\\KatanaSlash_low.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"KatanaSlashLowRight", m_pImage, Vector(0.f, 0.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.07f, 5, false);
	m_pAnimator->CreateAnimation(L"KatanaSlashLowLeft", m_pImage, Vector(0.f, 300.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.07f, 5, false);



	if (GAME->RightAttack == true)
	{
		m_pAnimator->Play(L"KatanaSlashLowRight", true);
	}
	else
	{
		m_pAnimator->Play(L"KatanaSlashLowLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
}

void CKatanaSlashLow::Update()
{
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
	AnimatorUpdate();
}

void CKatanaSlashLow::Render()
{
}

void CKatanaSlashLow::Release()
{
}

void CKatanaSlashLow::AnimatorUpdate()
{
	wstring str = L"KatanaSlashLow";

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

void CKatanaSlashLow::OnCollisionEnter(CCollider* pOtherCollider)
{
}
