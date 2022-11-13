#include "framework.h"
#include "CKatanaSlash.h"



CKatanaSlash::CKatanaSlash()
{
	m_layer = Layer::Missile;
	m_strName = L"KatanaSlash";
	m_pTimer = 0;
}

CKatanaSlash::~CKatanaSlash()
{
}

void CKatanaSlash::Init()
{
	m_pImage = RESOURCE->LoadImg(L"KatanaSlash", L"Image\\KatanaSlash.png");
	
	

	m_pAnimator = new CAnimator;

	m_pAnimator->CreateAnimation(L"KatanaSlash", m_pImage, Vector(0.f, 0.f), Vector(300.f, 200.f), Vector(300.f, 0.f), 0.02f, 5,false);
	
	
	m_pAnimator->Play(L"KatanaSlash", true);
	AddComponent(m_pAnimator);
	m_pTimer = 1.f;

}

void CKatanaSlash::Update()
{
	AnimatorUpdate();
	m_pTimer -= DT;
	if (m_pTimer <= 0)
	{
		DELETEOBJECT(this);
	}
}

void CKatanaSlash::Render()
{
}

void CKatanaSlash::Release()
{
}

void CKatanaSlash::AnimatorUpdate()
{
	wstring str = L"KatanaSlash";
	m_pAnimator->Play(str, false);
}

void CKatanaSlash::OnCollisionEnter(CCollider* pOtherCollider)
{
}
