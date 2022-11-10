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
	m_vecScale = Vector(38, 55);
	m_layer = Layer::Player;
	m_strName = L"플레이어";

	m_pIdleImage = nullptr;
	m_pMoveImage = nullptr;

	m_vecMoveDir = Vector(0, 0);
	m_vecLookDir = Vector(0, -1);
	m_bIsMove = false;
	actionTimer = 0;
	State = PlayerState::Idle;

	OnSlope = false;

	gravity = true;
	islanding = false;
	unGravityTimer = 0;
}

CPlayer::~CPlayer()
{
}

void CPlayer::Init()
{
	m_pIdleImage = RESOURCE->LoadImg(L"PlayerIdle", L"Image\\NULL\\IDLE\\IDLE_x2.png");
	m_pMoveImage = RESOURCE->LoadImg(L"PlayerMove", L"Image\\NULL\\RUN\\RUN_x2.png");
	m_pJumpImage = RESOURCE->LoadImg(L"PlayerJump", L"Image\\NULL\\JUMP\\JUMP_x2.png");
	m_pFallImage = RESOURCE->LoadImg(L"PlayerFall", L"Image\\NULL\\FALL\\FALL_x2.png");
	

	m_pAnimator = new CAnimator;
	m_pAnimator->CreateAnimation(L"IdleUp",			 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleRightUp",	 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleRight",		 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleRightDown",	 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleDown",		 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleLeftDown",	 m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleLeft",		 m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleLeftUp",		 m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);

	m_pAnimator->CreateAnimation(L"MoveUp",		   m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	m_pAnimator->CreateAnimation(L"MoveLeftUp",    m_pMoveImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
    m_pAnimator->CreateAnimation(L"MoveRightUp",   m_pMoveImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	
	m_pAnimator->CreateAnimation(L"MoveLeft",	   m_pMoveImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	m_pAnimator->CreateAnimation(L"MoveRight",	   m_pMoveImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);

	m_pAnimator->CreateAnimation(L"MoveDown",	   m_pMoveImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	m_pAnimator->CreateAnimation(L"MoveLeftDown",  m_pMoveImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	m_pAnimator->CreateAnimation(L"MoveRightDown", m_pMoveImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);

	m_pAnimator->Play(L"IdleDown", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(38, 55), Vector(0, 0));
}

void CPlayer::Update()
{
	m_bIsMove = false;//움직임 여부

	WhereAmI();//GAME에 좌표 기록
	unGravityTimer -= DT;

	//if (unGravityTimer <= 0)
	//{
	//	unGravityTimer = -1;
	//}

	//if (unGravityTimer >= 0)
	//{
	//	gravityPower = 0;
	//}

	gravityPower = 5+ flyTimer * flyTimer; //중력
	if (gravityPower >= 30)
	{
		gravityPower = 30;
	}

	if (islanding == true)//체공여부
	{
		flyTimer = 0;
	}
	else
	{
		flyTimer += DT;
	
		m_vecPos.y +=  gravityPower;
	}
	

	if (BUTTONSTAY(VK_LEFT))
	{
		switch (State)
		{
			case PlayerState::Idle:
			{
				State = PlayerState::Run;
				break;
			}
			case PlayerState::Run:
			{
				m_vecPos.x -= m_fSpeed * DT;
				m_bIsMove = true;
				m_vecMoveDir.x = -1;
				break;
			}
			case PlayerState::Attack:
			{
				break;
			}
			case PlayerState::Roll:
			{
				break;
			}
			case PlayerState::WallGrab:
			{
				break;
			}
			case PlayerState::Stun:
			{
				break;
			}
			case PlayerState::Flip:
			{
				break;
			}
			case PlayerState::Jump:
			{
				m_vecMoveDir.x = -1;
				break;
			}
			case PlayerState::Dance:
			{
				State = PlayerState::Run;
				break;
			}
	    }
	
	}
	else if (BUTTONSTAY(VK_RIGHT))
	{
		switch (State)
		{
		case PlayerState::Idle:
		{
			State = PlayerState::Run;
			break;
		}
		case PlayerState::Run:
		{
			m_vecPos.x += m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.x = +1;
			break;
		}
		case PlayerState::Attack:
		{
			break;
		}
		case PlayerState::Roll:
		{
			break;
		}
		case PlayerState::WallGrab:
		{
			break;
		}
		case PlayerState::Stun:
		{
			break;
		}
		case PlayerState::Flip:
		{
			break;
		}
		case PlayerState::Jump:
		{
			m_vecMoveDir.x = +1;
			break;
		}
		case PlayerState::Dance:
		{
			State = PlayerState::Run;
			break;
		}
	
	 }
	
	}
	else
	{
		m_vecMoveDir.x = 0;
	}

	if (BUTTONDOWN(VK_UP))
	{
		switch (State)
		{
		case PlayerState::Idle:
		{
			islanding = false;
			m_vecMoveDir.y = -1;
			m_vecPos.y -= 100 * DT;
			unGravityTimer = 10;
			m_bIsMove = true;
			State = PlayerState::Jump;
			break;
		}
		case PlayerState::Run:
		{
			islanding = false;
			m_vecMoveDir.y = -1;
			m_vecPos.y -= 100 * DT;
			m_bIsMove = true;
			State = PlayerState::Jump;
			break;
		}
		case PlayerState::Attack:
		{
			break;
		}
		case PlayerState::Roll:
		{
			break;
		}
		case PlayerState::WallGrab:
		{
			break;
		}
		case PlayerState::Stun:
		{
			break;
		}
		case PlayerState::Flip:
		{
			break;
		}
		case PlayerState::Jump:
		{	
		
			break;
		}
		case PlayerState::Dance:
		{
			State = PlayerState::Run;
			break;
		}

		}
		
		
		
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
		islanding = true;
	}
	if (pTarget == L"Wall")
	{
		islanding = true;
	}
	if (pTarget == L"R_High_Slope")
	{
		
	}
	if (pTarget == L"L_High_Slope")
	{

	}
	if (pTarget == L"Platfoam")
	{
		islanding = true;
	}
}

void CPlayer::OnCollisionStay(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"Ground")
	{
		//if (m_vecPos.x < pOtherCollider->GetPos().x)//왼쪽에서 부딪히기
		//{
		//	m_vecPos.x = pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - m_vecScale.x / 2 + 4;
		//}
		//else//오른쪽에서 부딪히기
		//{
		//	m_vecPos.x = pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + m_vecScale.x / 2 - 4;
		//}

		
		
			Logger::Debug(L"그라운드");
			if (m_vecPos.y < pOtherCollider->GetPos().y)//땅밟고 서있기
			{
				m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2+2 ;
			}
		
		else //천장에 머리박기
		{
			m_vecPos.y = pOtherCollider->GetPos().y+ pOtherCollider->GetScale().y/2 + m_vecScale.y / 2;
		}

	}
	if (pTarget == L"Wall")
	{	
		//if (m_vecPos.y < pOtherCollider->GetPos().y - pOtherCollider->GetScale().y/2)
		//{


		//	m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 + 8;

		//}
		//else if (m_vecPos.y > pOtherCollider->GetPos().y + pOtherCollider->GetScale().y/2) //천장에 머리박기
		//{
		//	m_vecPos.y = pOtherCollider->GetPos().y + pOtherCollider->GetScale().y / 2 + m_vecScale.y / 2;
		//}
		/*else
		{*/
			if (m_vecPos.x < pOtherCollider->GetPos().x)//왼쪽에서 부딪히기
			{
				m_vecPos.x = pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - m_vecScale.x / 2 ;
			}
			else//오른쪽에서 부딪히기
			{
				m_vecPos.x = pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + m_vecScale.x / 2 ;
			}
		/*}*/


		
	}
	if (pTarget == L"R_High_Slope")
	{	
		
		//m_vecPos.y = (pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2) - (m_vecPos.x) - m_vecScale.y / 2 + 4;
		float Slope;
		Slope = (-(pOtherCollider->GetScale().y / pOtherCollider->GetScale().x) * (m_vecPos.x - pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2) + pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2) - m_vecScale.y / 2;
		if (Slope < m_vecPos.y)
		{
			m_vecPos.y = Slope;
			
		}
	}
	if (pTarget == L"L_High_Slope")
	{	
		float Slope2;
		Slope2 = ((pOtherCollider->GetScale().y / pOtherCollider->GetScale().x) * (m_vecPos.x - pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2) + pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2)-m_vecScale.y/2;
		if (Slope2 < m_vecPos.y)
		{
			m_vecPos.y = Slope2;
			
		}
	}
	if (pTarget == L"Platfoam")
	{
		if (m_vecPos.y < pOtherCollider->GetPos().y)//땅밟고 서있기
		{
			m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2+2 ;
		}
	}




}

void CPlayer::OnCollisionExit(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();
	if (pTarget == L"Ground")
	{
		islanding = false;
	}
	if (pTarget == L"Wall")
	{
		islanding = false;
	}
	if (pTarget == L"R_High_Slope")
	{
		
	}
	if (pTarget == L"L_High_Slope")
	{
		
	}
	if (pTarget == L"Platfoam")
	{
		islanding = false;
	}
}

void CPlayer::WhereAmI()
{
	PLAYERPOSITION= m_vecPos;
}
