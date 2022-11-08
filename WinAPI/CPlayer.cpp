#include "framework.h"
#include "CPlayer.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CResourceManager.h"
#include "CCollider.h"
#include "CImage.h"
#include "CAnimator.h"

#include "CMissile.h"

CPlayer::CPlayer()
{
	m_vecPos = Vector(0, 0);
	m_vecScale = Vector(100, 100);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);
	m_bIsMove = false;

	State = PlayerState::Idle;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\PlayerIdle.png");
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\PlayerMove.png");

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"IdleUp", m_pIdleImage, Vector(8.f, 0.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleRightUp", m_pIdleImage, Vector(8.f, 70.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleRight", m_pIdleImage, Vector(8.f, 140.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleRightDown", m_pIdleImage, Vector(8.f, 210.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleDown", m_pIdleImage, Vector(8.f, 280.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleLeftDown", m_pIdleImage, Vector(8.f, 350.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleLeft", m_pIdleImage, Vector(8.f, 420.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);
	m_pAnimator->CreateAnimation(L"IdleLeftUp", m_pIdleImage, Vector(8.f, 490.f), Vector(80.f, 70.f), Vector(80.f, 0.f), 0.1f, 7);

	m_pAnimator->CreateAnimation(L"MoveUp", m_pMoveImage, Vector(0.f, 0.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveRightUp", m_pMoveImage, Vector(0.f, 79.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveRight", m_pMoveImage, Vector(0.f, 158.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveRightDown", m_pMoveImage, Vector(0.f, 237.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveDown", m_pMoveImage, Vector(0.f, 316.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveLeftDown", m_pMoveImage, Vector(0.f, 395.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveLeft", m_pMoveImage, Vector(0.f, 474.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->CreateAnimation(L"MoveLeftUp", m_pMoveImage, Vector(0.f, 553.f), Vector(80.f, 75.f), Vector(84.f, 0.f), 0.05f, 16);
	m_pAnimator->Play(L"IdleDown", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
}

void CPlayer::Update()
{
	m_bIsMove = false;
	WhereAmI();

	if (BUTTONSTAY(VK_LEFT))
	{
		switch ((int)State)
		{
			case 0:
			{

			}
			case 1:
			{

			}
			case 2:
			{

			}
			case 3:
			{


			}
			case 4:
			{

			}
			case 5:
			{

			}
			case 6:
			{

			}
			case 7:
			{

			}
			case 8:
			{

			}
	    }
		m_vecPos.x -= m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.x = -1;
	}
	else if (BUTTONSTAY(VK_RIGHT))
	{
	 switch ((int)State)
	 {
		case 0:
		{

		}
		case 1:
		{

		}
		case 2:
		{

		}
		case 3:
		{


		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{

		}
		case 7:
		{

		}
		case 8:
		{

		}
	 }
		m_vecPos.x += m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.x = +1;
	}
	else
	{
		m_vecMoveDir.x = 0;
	}

	if (BUTTONSTAY(VK_UP))
	{
		switch ((int)State)
		{
		case 0:
		{

		}
		case 1:
		{

		}
		case 2:
		{

		}
		case 3:
		{


		}
		case 4:
		{

		}
		case 5:
		{

		}
		case 6:
		{

		}
		case 7:
		{

		}
		case 8:
		{

		}
		}
		m_vecPos.y -= m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.y = +1;
	}
	else if (BUTTONSTAY(VK_DOWN))
	{
		m_vecPos.y += m_fSpeed * DT;
		m_bIsMove = true;
		m_vecMoveDir.y = -1;
	}
	else
	{
		m_vecMoveDir.y = 0;
	}

	//if (BUTTONDOWN(VK_SPACE))
	//{
	//	CreateMissile();
	//}

	AnimatorUpdate();
}

void CPlayer::Render()
{
}

void CPlayer::Release()
{
}

void CPlayer::AnimatorUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	wstring str = L"";

	if (m_bIsMove)	str += L"Move";
	else			str += L"Idle";

	if (m_vecLookDir.x > 0) str += L"Right";
	else if (m_vecLookDir.x < 0) str += L"Left";

	if (m_vecLookDir.y > 0) str += L"Up";
	else if (m_vecLookDir.y < 0) str += L"Down";

	m_pAnimator->Play(str, false);
}

void CPlayer::CreateMissile()
{
	Logger::Debug(L"미사일 생성");

	CMissile* pMissile = new CMissile();
	pMissile->SetPos(m_vecPos);
	pMissile->SetDir(Vector(1, 0));
	ADDOBJECT(pMissile);

	CMissile* pMissile1 = new CMissile();
	pMissile1->SetPos(m_vecPos);
	pMissile1->SetDir(Vector(1, -1));
	ADDOBJECT(pMissile1);

	CMissile* pMissile2 = new CMissile();
	pMissile2->SetPos(m_vecPos);
	pMissile2->SetDir(Vector(1, 1));
	ADDOBJECT(pMissile2);

	CMissile* pMissile3 = new CMissile();
	pMissile3->SetPos(m_vecPos);
	pMissile3->SetDir(Vector(3, 1));
	ADDOBJECT(pMissile3);

	//CMissile* pMissile4 = new CMissile();
	//pMissile4->SetPos(m_vecPos);
	//pMissile4->SetDir(Vector(3, -1));
	//ADDOBJECT(pMissile4);
}

void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"Ground")
	{
		
	}
	if (pTarget == L"Wall")
	{

	}
	if (pTarget == L"R_High_Slope")
	{

	}
	if (pTarget == L"L_High_Slope")
	{

	}
	if (pTarget == L"Platfoam")
	{

	}
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"Ground")
	{
		Logger::Debug(L"그라운드");
		m_vecPos.y = pOtherCollider->GetPos().y-4;
	}
	if (pTarget == L"Wall")
	{
		m_vecPos.x= pOtherCollider->GetPos().x;
	}
	if (pTarget == L"R_High_Slope")
	{	
		
		m_vecPos.y = m_vecPos.x-pOtherCollider->GetPos().x-4;
	}
	if (pTarget == L"L_High_Slope")
	{
		m_vecPos.y = pOtherCollider->GetPos().x- m_vecPos.x-4;
	}
	if (pTarget == L"Platfoam")
	{
		m_vecPos.y = pOtherCollider->GetPos().y-4;
	}




}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
}

void CPlayer::WhereAmI()
{
	PLAYERPOSITION= m_vecPos;
}
