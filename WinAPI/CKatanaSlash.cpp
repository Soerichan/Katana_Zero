#include "framework.h"
#include "CKatanaSlash.h"



CKatanaSlash::CKatanaSlash()
{
	m_layer = Layer::Missile;
	m_strName = L"KatanaSlash";
	m_pTimer = 0;
	m_fDegree = 0;
}

CKatanaSlash::~CKatanaSlash()
{
}

void CKatanaSlash::Init()
{	
	

	m_pImage = RESOURCE->LoadImg(L"KatanaSlash", L"Image\\KatanaSlash.png");
	
	

	m_pAnimator = new CAnimator;

	
	m_pAnimator->CreateAnimation(L"KatanaSlashRight", m_pImage, Vector(0.f, 0.f), Vector(212.f, 64.f), Vector(400.f, 0.f), 0.07f, 5,false);
	m_pAnimator->CreateAnimation(L"KatanaSlashLeft", m_pImage, Vector(0.f, 200.f), Vector(212.f, 64.f), Vector(400.f, 0.f), 0.07f, 5,false);
	
	
	
	if (GAME->RightAttack == true)
	{
		m_pAnimator->Play(L"KatanaSlashRight", true);
	}
	else
	{
		m_pAnimator->Play(L"KatanaSlashLeft", true);
	}

	AddComponent(m_pAnimator);
	m_pTimer = 0.35f;
	AddCollider(ColliderType::Rect, Vector(300, 200), Vector(0, 0));

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

void CKatanaSlash::OnCollisionEnter(CCollider* pOtherCollider)
{
}
