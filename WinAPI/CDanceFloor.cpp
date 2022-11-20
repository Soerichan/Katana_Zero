#include "framework.h"
#include "CDanceFloor.h"

CDanceFloor::CDanceFloor()
{
	m_layer = Layer::DanceFloor;
	m_strName = L"DanceFloor";
	m_bTwo = false;
	
}

CDanceFloor::~CDanceFloor()
{
}

void CDanceFloor::SetTwo(bool Istwo)
{
	m_bTwo = Istwo;
}

void CDanceFloor::AnimatorUpdate()
{
	wstring str = L"DanceFloor";
	if (m_bTwo)
	{
		str += L"2";
	}
	else
	{
		
	}
	m_pAnimator->Play(str, false);
}

void CDanceFloor::Init()
{
	m_pImage = RESOURCE->LoadImg(L"DanceFloor", L"Image\\DanceFloor.png");



	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"DanceFloor", m_pImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 12);
	m_pAnimator->CreateAnimation(L"DanceFloor2", m_pImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 12);



		
	if (m_bTwo)
	{
		m_pAnimator->Play(L"DanceFloor2", true);
	}
	else
	{
		m_pAnimator->Play(L"DanceFloor", true);
	}
	
	AddComponent(m_pAnimator);
	
	AddCollider(ColliderType::Rect, Vector(100, 100), Vector(0, 0));
}

void CDanceFloor::Update()
{
	AnimatorUpdate();
}

void CDanceFloor::Render()
{
}

void CDanceFloor::Release()
{
}

void CDanceFloor::OnCollisionEnter(CCollider* pOtherCollider)
{
	GAME->InDanceFloor = true;
}

void CDanceFloor::OnCollisionStay(CCollider* pOtherCollider)
{
	GAME->InDanceFloor = true;
}

void CDanceFloor::OnCollisionExit(CCollider* pOtherCollider)
{
	GAME->InDanceFloor = false;
}
