#include "framework.h"
#include "CDoor.h"


CDoor::CDoor()
{
	m_fTimer = 0.4f;
	m_pOpenImage = nullptr;
	m_pAnimationImage = nullptr;
	m_pCloseImage = nullptr;
	m_layer = Layer::Door;
	m_strName = L"Door";
	m_vecScale = Vector(38, 146);
	m_bIsOpen = false;
	m_fOpenTimer = 0.01f;
	m_State = DoorState::Close;
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
	if (PLAYERPOSITION.x>m_vecPos.x)
	{
		RemoveCollider();
		m_layer = Layer::Missile;
		AddCollider(ColliderType::Rect, Vector(120, 120), Vector(-50, 0));
		
	}
	else
	{
		RemoveCollider();
		m_layer = Layer::Missile;
		AddCollider(ColliderType::Rect, Vector(120, 120), Vector(50, 0));
		
	}

	m_bIsOpen = true;
}

void CDoor::Init()
{
	m_pCloseImage=RESOURCE->LoadImg(L"ClosedDoor",L"Image\\Door\\spr_door_animation_club_0.png");
	m_pAnimationImage=RESOURCE->LoadImg(L"DoorAnimation",L"Image\\Door\\DOOR3.png");
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

	

	if (m_State == DoorState::Close)
	{

	}
	if (m_State == DoorState::Opening)
	{
		m_fOpenTimer -= DT;

		if (m_fOpenTimer <= 0)
		{
			Open();
			m_State = DoorState::Open;
		}
	}
	if(m_State == DoorState::Open)
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

	

	if (m_State == DoorState::Close)
	{
		RENDER->Image(m_pCloseImage,
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f);
	}
	if (m_State == DoorState::Opening)
	{

	}
	if (m_State == DoorState::Open)
	{
		RENDER->Image(m_pOpenImage,
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f);
	}
}

void CDoor::Release()
{
}

void CDoor::AnimatorUpdate()
{
	if (m_State == DoorState::Opening)
	{
		wstring str = L"Door";

		if (PLAYERPOSITION.x < m_vecPos.x)
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
		if (m_State == DoorState::Close)
			m_State = DoorState::Opening;
	}
}
