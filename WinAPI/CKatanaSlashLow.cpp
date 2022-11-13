#include "framework.h"
#include "CKatanaSlashLow.h"

CKatanaSlashLow::CKatanaSlashLow()
{
}

CKatanaSlashLow::~CKatanaSlashLow()
{
}

void CKatanaSlashLow::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KatanaSlashlow", L"Image\\KatanaSlash_low.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"KatanaSlashlow", m_pImage, Vector(0.f, 0.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.02f, 5, false);
	m_pAnimator->Play(L"KatanaSlashlow", true);
	AddComponent(m_pAnimator);
}

void CKatanaSlashLow::Update()
{
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
	wstring str = L"KatanaSlashlow";
	m_pAnimator->Play(str, false);
}

void CKatanaSlashLow::OnCollisionEnter(CCollider* pOtherCollider)
{
}
