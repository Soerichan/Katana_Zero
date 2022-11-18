#include "framework.h"
#include "CDoor.h"

CDoor::CDoor()
{
	m_fTimer = 1.65f;
	m_pOpenImage = nullptr;
	m_pAnimationImage = nullptr;
	m_pCloseImage = nullptr;
	m_layer = Layer::Door;
	m_strName = L"Door";
	m_vecScale = Vector(19, 64);
	m_bIsOpen = false;
}

CDoor::~CDoor()
{
}

bool CDoor::GetCheckOpen()
{
	return m_bIsOpen;
}

void CDoor::Open()
{
	if (GAME->RightAttack)
	{
		RemoveCollider();
		AddCollider(ColliderType::Rect, Vector(100, 100), Vector(100, 0));
		m_bIsOpen = true;
	}
	else
	{
		RemoveCollider();
		AddCollider(ColliderType::Rect, Vector(100, 100), Vector(-100, 0));
		m_bIsOpen =true;
	}
}

void CDoor::Init()
{
	m_pCloseImage=RESOURCE->LoadImg(L"ClosedDoor",L"Image\\Door\\spr_door_animation_club_0.png");
	m_pAnimationImage=RESOURCE->LoadImg(L"DoorAnimation",L"Image\\Door\\DOOR.png");
	m_pOpenImage = RESOURCE->LoadImg(L"OpenedDoor", L"Image\\Door\\spr_door_animation_club_16.png");

	m_pAnimator = new CAnimator;


	m_pAnimator->CreateAnimation(L"DoorToRight", m_pAnimationImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);
	m_pAnimator->CreateAnimation(L"DoorToLeft", m_pAnimationImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);



	/*if (GAME->RightAttack == false)
	{
		m_pAnimator->Play(L"DoorToLeft", true);
	}
	else
	{
		m_pAnimator->Play(L"DoorToLeft", true);
	}*/

	AddComponent(m_pAnimator);
	
	AddCollider(ColliderType::Rect, Vector(20, 100), Vector(0, 0));
}

void CDoor::Update()
{
	AnimatorUpdate();
	if (m_bIsOpen)
	{
		m_fTimer -= DT;
		if (m_fTimer <= 0)
		{
			RemoveCollider();
		}
	}
}

void CDoor::Render()
{

	if (m_bIsOpen == false)
	{

		RENDER->Image(m_pCloseImage,
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f);
	}
	/*else
	{
		if (m_fTimer <= 0)
		{
			RENDER->Image(m_pOpenImage,
				m_vecPos.x - m_vecScale.x * 0.5f,
				m_vecPos.y - m_vecScale.y * 0.5f,
				m_vecPos.x + m_vecScale.x * 0.5f,
				m_vecPos.y + m_vecScale.y * 0.5f);
		}
	}*/
}

void CDoor::Release()
{
}

void CDoor::AnimatorUpdate()
{
	if (m_bIsOpen)
	{
		wstring str = L"Door";

		if (GAME->RightAttack)
		{
			str += L"ToRight";
		}
		else
		{
			str += L"ToLeft";
		}
		m_pAnimator->Play(str, false);
	}
}

void CDoor::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"플레이어")
	{
		if(m_bIsOpen==false)
		Open();
	}
}
