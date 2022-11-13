#include "framework.h"
#include "CKatanaSlashHigh.h"

CKatanaSlashHigh::CKatanaSlashHigh()
{
}

CKatanaSlashHigh::~CKatanaSlashHigh()
{
}

void CKatanaSlashHigh::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KatanaSlashhigh", L"Image\\KatanaSlash_high.png");
	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"KatanaSlashhigh", m_pImage, Vector(0.f, 0.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.02f, 5, false);
	m_pAnimator->Play(L"KatanaSlashhigh", true);
	AddComponent(m_pAnimator);
}

void CKatanaSlashHigh::Update()
{
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
	wstring str = L"KatanaSlashhigh";
	m_pAnimator->Play(str, false);
}

void CKatanaSlashHigh::OnCollisionEnter(CCollider* pOtherCollider)
{
}
