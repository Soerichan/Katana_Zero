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
	WallGrabTimer = 0;

	accel = 0;
	velocity = 0;
	gravityPower = 3;
	resistance = 0;

	Isgrabed = nullptr;
	FlipDir = 0;
	FlipTimer = 0;
	
	RollTimer = 0;

	AttackTimer = 0;
	AttackPos = {};
	IsHit = false;
	IsAttacking = false;
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
	m_pAttackImage = RESOURCE->LoadImg(L"PlayerAttack", L"Image\\NULL\\ATTACK\\ATTACK_x2.png");
	m_pCrouchImage = RESOURCE->LoadImg(L"PlayerCrouch", L"Image\\NULL\\CROUCH\\CROUCH_x2.png");
	m_pDanceImage = RESOURCE->LoadImg(L"PlayerDance", L"Image\\NULL\\DANCE\\DANCE_x2.png");
	m_pDoor_KickImage = RESOURCE->LoadImg(L"PlayerDoor_Kick", L"Image\\NULL\\DOOR_KICK\\DOOR_KICK_x2.png");
	m_pEarPhoneImage = RESOURCE->LoadImg(L"PlayerEarPhone", L"Image\\NULL\\EARPHONE\\EARPHONE_x2.png");
	m_pFlipImage = RESOURCE->LoadImg(L"PlayerFlip", L"Image\\NULL\\FLIP\\FLIP_x2.png");
	m_pHurtCoverImage = RESOURCE->LoadImg(L"PlayerHurtCover", L"Image\\NULL\\HURTCOVER\\HURTCOVER_x2.png");
	m_pHurtFlyImage = RESOURCE->LoadImg(L"PlayerHurtFly", L"Image\\NULL\\HURTFLY\\HURTFLY_x2.png");
	m_pHurtGroundImage = RESOURCE->LoadImg(L"PlayerHurtGround", L"Image\\NULL\\HURTFLY\\HURTFLY_x2.png");
 	m_pRollImage = RESOURCE->LoadImg(L"PlayerRoll", L"Image\\NULL\\ROLL\\ROLL_x2.png");
	m_pWallGrabImage = RESOURCE->LoadImg(L"PlayerWallGrab", L"Image\\NULL\\WALLGRAB\\WALLGRAB_x2.png");
	

	m_pAnimator = new CAnimator;
	
	m_pAnimator->CreateAnimation(L"IdleRight",		 m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleLeft",		 m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11);
	m_pAnimator->CreateAnimation(L"IdleCrouch",		 m_pCrouchImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3,false);
	m_pAnimator->CreateAnimation(L"IdleLeftCrouch",	 m_pCrouchImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3,false);
	m_pAnimator->CreateAnimation(L"IdleRightCrouch",	 m_pCrouchImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3,false);
	//m_pAnimator->CreateAnimation(L"IdleUp",			 m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4,false);
	//m_pAnimator->CreateAnimation(L"MoveUp",		     m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	//m_pAnimator->CreateAnimation(L"MoveLeftUp",      m_pJumpImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	//m_pAnimator->CreateAnimation(L"IdleLeftUp",		 m_pJumpImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
   
	//m_pAnimator->CreateAnimation(L"MoveRightUp",     m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	//m_pAnimator->CreateAnimation(L"IdleRightUp",	 m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	
	m_pAnimator->CreateAnimation(L"MoveLeft",	     m_pMoveImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);
	m_pAnimator->CreateAnimation(L"MoveRight",	     m_pMoveImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 10);


	m_pAnimator->CreateAnimation(L"JumpLeft", m_pJumpImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 4);
	m_pAnimator->CreateAnimation(L"JumpRight", m_pJumpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 4);

	m_pAnimator->CreateAnimation(L"FallLeft", m_pFallImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 4);
	m_pAnimator->CreateAnimation(L"FallRight", m_pFallImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 4);

	m_pAnimator->CreateAnimation(L"AttackLeft", m_pAttackImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 7,false);
	m_pAnimator->CreateAnimation(L"AttackRight", m_pAttackImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 7,false);

	m_pAnimator->CreateAnimation(L"Door_KickLeft", m_pDoor_KickImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.05f, 10,false);
	m_pAnimator->CreateAnimation(L"Door_KickRight", m_pDoor_KickImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.05f, 10,false);

	m_pAnimator->CreateAnimation(L"DanceLeft", m_pDanceImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 12);
	m_pAnimator->CreateAnimation(L"DanceRight", m_pDanceImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 12);

	m_pAnimator->CreateAnimation(L"HurtCoverLeft", m_pHurtCoverImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 9,false);
	m_pAnimator->CreateAnimation(L"HurtCoverRight", m_pHurtCoverImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 9,false);

	m_pAnimator->CreateAnimation(L"HurtFlyLeft", m_pHurtFlyImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 6,false);
	m_pAnimator->CreateAnimation(L"HurtFlyRight", m_pHurtFlyImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 6, false);

	m_pAnimator->CreateAnimation(L"HurtGroundLeft", m_pHurtGroundImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 6, false);
	m_pAnimator->CreateAnimation(L"HurtGroundRight", m_pHurtGroundImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 6, false);


	m_pAnimator->CreateAnimation(L"WallGrabLeft", m_pWallGrabImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 2,false);
	m_pAnimator->CreateAnimation(L"WallGrabRight", m_pWallGrabImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 2,false);


	m_pAnimator->CreateAnimation(L"RollLeft", m_pRollImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 7,false);
	m_pAnimator->CreateAnimation(L"RollRight", m_pRollImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.06f, 7,false);


	m_pAnimator->CreateAnimation(L"EarPhoneLeft", m_pEarPhoneImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3,false);
	m_pAnimator->CreateAnimation(L"EarPhoneRight", m_pEarPhoneImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 3,false);

	m_pAnimator->CreateAnimation(L"FlipLeft", m_pFlipImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.03f, 11,false);
	m_pAnimator->CreateAnimation(L"FlipRight", m_pFlipImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.03f, 11,false);

	//m_pAnimator->CreateAnimation(L"MoveDown",	     m_pFallImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4);
	//m_pAnimator->CreateAnimation(L"MoveLeftDown",    m_pFallImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4);
	//m_pAnimator->CreateAnimation(L"MoveRightDown",   m_pFallImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4);
	
	


	m_pAnimator->Play(L"IdleRight", false);
	AddComponent(m_pAnimator);

	AddCollider(ColliderType::Rect, Vector(38, 55), Vector(0, 0));

	m_vecMoveDir.x = -1;
	m_vecMoveDir.y = +1;
}

void CPlayer::Update()
{
	m_bIsMove = false;//움직임 여부

	WhereAmI();//GAME에 좌표 기록
	WhatIsMyState();//GAME에 상태 기록
	
	
	
#pragma region Jump관련
	if (jumpAction == true)
	{
		velocity +=  (accel * DT)-resistance;//속력의 가속
		accel -= 700*DT;//힘의 감소
		m_vecPos.y -= velocity * DT; //변위
		resistance += gravityPower * DT;//중력

		if (accel <= 0)
		{
			accel = 0;
		}
		if (resistance >= 5)
		{
			resistance = 5;
		}
	}
	else
	{
		velocity = 0;
		accel = 0;
		resistance = 0;
		m_vecPos.y += 1; //기본중력
		
	}

	if (islanding == true)
	{
		jumpAction = false;
		//m_vecMoveDir.y = 0;
	}


	if (velocity <= 0 && State == PlayerState::Jump)
	{
		State = PlayerState::Fall;
	}

#pragma endregion

#pragma region WallGrab관련

	if (State == PlayerState::WallGrab)
	{
		WallGrabTimer -= DT;

		if (WallGrabTimer > 0)
		{
			velocity = 0;
		}

		if (islanding == true)
		{
			State = PlayerState::Idle;
		}
	}



#pragma endregion


#pragma region Flip관련

	if (State == PlayerState::Flip)
	{		
		WallGrabTimer = 0;
		

		if (FlipTimer >= 1)
		{
			velocity = 450;
		}
		FlipTimer -= DT;
		
		
		
			m_vecPos.x += m_fSpeed * DT * FlipDir;
		
			if (jumpAction == false)
			{
				State = PlayerState::Idle;
			}

	}
	else
	{
		FlipDir = 0;
	}





#pragma endregion


#pragma region Fall관련
	if (State == PlayerState::Fall)
	{
		FlipTimer -= DT;

		if (jumpAction == false)
		{
			State = PlayerState::Idle;
		}
	}
#pragma endregion

#pragma region Roll관련
	if (State == PlayerState::Roll)
	{	
		RollTimer -= DT;

		if (RollTimer >= 0)
		{
			m_vecPos.x += 1.5*m_fSpeed * DT * m_vecMoveDir.x;
		}
		else
		{
			
			State = PlayerState::Idle;
		}
	}
#pragma endregion

#pragma region Run관련
	if (State == PlayerState::Run)
	{
		if (BUTTONUP(VK_LEFT))
		{
			State = PlayerState::Idle;
		}
		else if (BUTTONUP(VK_RIGHT))
		{
			State = PlayerState::Idle;
		}
	}
#pragma endregion


#pragma region Attack관련
	if (State == PlayerState::Attack)
	{
		AttackTimer -= DT;
		m_vecPos.x += AttackPos.x * 500 *DT;
		m_vecPos.y += AttackPos.y * 400 *DT;

		if (AttackTimer <= 0)
		{	
			IsAttacking = false;
			m_vecPos.x += AttackPos.x * 600 * DT;
			State = PlayerState::Fall;
		}
	}


#pragma endregion

#pragma region State관련
	//if (islanding == true)
	//{
	//	State = PlayerState::Idle;
	//	m_vecMoveDir.y = 0;
	//	m_bIsMove = false;
	//}



#pragma endregion
	//if (unGravityTimer <= 0)
	//{
	//	unGravityTimer = -1;
	//}

	//if (unGravityTimer >= 0)
	//{
	//	gravityPower = 0;
	//}



	
#pragma region Key입력관련

	if (LMOUSEDOWN(false))
	{	
		switch (State)
		{
		case PlayerState::Idle:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Run:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Attack:
			//if (IsHit == false)
			//{
			//	State = PlayerState::Attack;
			//	Attack();
			//}
			break;
		case PlayerState::Roll:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::WallGrab:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Stun:
			break;
		case PlayerState::Flip:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Jump:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Fall:
			if (IsHit == false)
			{
				State = PlayerState::Attack;
				Attack();
			}
			break;
		case PlayerState::Dance:
			State = PlayerState::Attack;
			Attack();
			break;
		case PlayerState::Die:
			break;
		
		}
		
	}
	else if (!BUTTONSTAY(VK_DOWN) && BUTTONSTAY(VK_LEFT))
	{
		switch (State)
		{
			case PlayerState::Idle:
			{	
				m_vecPos.x -= m_fSpeed * DT;
				m_bIsMove = true;
				m_vecMoveDir.x = -1;
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
			case PlayerState::Fall:
			{

				m_vecPos.x -= 0.45f * m_fSpeed * DT;
				m_bIsMove = true;
				m_vecMoveDir.x = -1;
				break;
			}
			case PlayerState::Jump:
			{	
				m_vecPos.x -= 0.35f * m_fSpeed * DT;
				m_bIsMove = true;
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
	else if (!BUTTONSTAY(VK_DOWN) && BUTTONSTAY(VK_RIGHT))
	{
		switch (State)
		{
		case PlayerState::Idle:
		{
			m_vecPos.x += m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.x = +1;
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
		case PlayerState::Fall:
		{
			m_vecPos.x += 0.45f * m_fSpeed * DT;
			m_bIsMove = true;
			m_vecMoveDir.x = +1;

			break;
		}
		case PlayerState::Jump:
		{	
			m_vecPos.x += 0.45f*m_fSpeed * DT;
			m_bIsMove = true;
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
		//m_vecMoveDir.x = 0;
	}

	if (BUTTONDOWN(VK_UP))
	{
		switch (State)
		{
		case PlayerState::Idle:
		{	
		
			State = PlayerState::Jump;
			Jump();
			
			break;
		}
		case PlayerState::Run:
		{
			
			State = PlayerState::Jump;
			Jump();

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
			State = PlayerState::Flip;
			Flip();

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
		case PlayerState::Fall:
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
	
	else if (BUTTONUP(VK_DOWN))
	{
		//m_vecPos.y += m_fSpeed * DT;

		m_vecMoveDir.y = 0;
	}
	else if (BUTTONSTAY(VK_DOWN) && BUTTONDOWN(VK_LEFT))
	{	
		switch (State)
		{
		case PlayerState::Idle:
			State = PlayerState::Roll;
			m_vecMoveDir.x = -1;
			Roll();
			break;
		case PlayerState::Run:
			State = PlayerState::Roll;
			m_vecMoveDir.x = -1;
			Roll();
			break;
		case PlayerState::Attack:
			break;
		case PlayerState::Roll:
			break;
		case PlayerState::WallGrab:
			break;
		case PlayerState::Stun:
			break;
		case PlayerState::Flip:
			break;
		case PlayerState::Jump:
			break;
		case PlayerState::Fall:
			break;
		case PlayerState::Dance:
			break;
		case PlayerState::Die:
			break;
		
		}
		
	}
	else if (BUTTONSTAY(VK_DOWN)&&BUTTONDOWN(VK_RIGHT))
	{
		switch (State)
		{
		case PlayerState::Idle:
			State = PlayerState::Roll;
			m_vecMoveDir.x = +1;
			Roll();
			break;
		case PlayerState::Run:
			State = PlayerState::Roll;
			m_vecMoveDir.x = +1;
			Roll();
			break;
		case PlayerState::Attack:
			break;
		case PlayerState::Roll:
			break;
		case PlayerState::WallGrab:
			break;
		case PlayerState::Stun:
			break;
		case PlayerState::Flip:
			break;
		case PlayerState::Jump:
			break;
		case PlayerState::Fall:
			break;
		case PlayerState::Dance:
			break;
		case PlayerState::Die:
			break;

		}
	}
	else if (BUTTONSTAY(VK_DOWN))
	{
	//m_vecPos.y += m_fSpeed * DT;
	
	m_vecMoveDir.y = -1;
	}
	else if (BUTTONSTAY(VK_F3))
	{ 
	Dance();
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
	WhereWasI();
}

#pragma endregion

void CPlayer::Render()
{
}

void CPlayer::Release()
{
}

void CPlayer::Jump()
{	
	jumpAction = true;
	islanding = false;
	accel = 500;
	velocity = 200;
	m_vecMoveDir.y = +1;
	
}

void CPlayer::Flip()
{	
	if (Isgrabed->GetPos().x < m_vecPos.x)
	{	
		
		FlipDir = 1.f;
		FlipTimer = 1.1f;
		Jump();
	}
	else
	{
		FlipDir = -1;
		FlipTimer = 1.1;
		Jump();
	}

}

void CPlayer::Roll()
{
	RollTimer = 0.5f;
	

}

void CPlayer::Attack()
{	
	AttackTimer = 0.5f;
	AttackPos = (MOUSEWORLDPOS-m_vecPos).Normalized();

	IsAttacking = true;
	if (MOUSEWORLDPOS.x < m_vecPos.x)
	{
		m_vecMoveDir.x = -1;
	}
	else
	{
		m_vecMoveDir.x = +1;
	}
	m_vecPos.y -= 10;

	
}

void CPlayer::Dance()
{
	State = PlayerState::Dance;
}


#pragma region 애니메이터 업데이트
void CPlayer::AnimatorUpdate()
{
	if (m_vecMoveDir.Length() > 0)
		m_vecLookDir = m_vecMoveDir;

	wstring str = L"";

	//if (m_bIsMove)	str += L"Move";
	//else			str += L"Idle";

	//if (m_vecLookDir.x > 0) str += L"Right";
	//else if (m_vecLookDir.x < 0) str += L"Left";


	//if (m_vecLookDir.y > 0) str += L"Up";
	//else if (m_vecLookDir.y < 0) str += L"Down";
	//if (GAME->PrevPlayerPos.y - PLAYERPOSITION.y > 0) str += L"Up";
	//else if (GAME->PrevPlayerPos.y - PLAYERPOSITION.y < 0) str += L"Down";

	switch (State)
	{
	case PlayerState::Idle:

		str += L"Idle";

		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		if (m_vecLookDir.y < 0) str += L"Crouch";

		break;

	case PlayerState::Run:

		str += L"Move";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;

	case PlayerState::Attack:

		str += L"Attack";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::Roll:

		str += L"Roll";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::WallGrab:

		str += L"WallGrab";
		if (Isgrabed->GetPos().x>m_vecPos.x) str += L"Right";
		else if (Isgrabed->GetPos().x < m_vecPos.x) str += L"Left";

		break;
	case PlayerState::Stun:

		str += L"Stun";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::Flip:

		str += L"Flip";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::Jump:

		str += L"Jump";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";


		break;
	case PlayerState::Fall:

		str += L"Fall";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::Dance:

		str += L"Dance";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";

		break;
	case PlayerState::Die:

		str += L"Die";
		if (m_vecLookDir.x > 0) str += L"Right";
		else if (m_vecLookDir.x < 0) str += L"Left";
		break;
	}

	m_pAnimator->Play(str, false);
}

#pragma endregion

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
#pragma region 충돌
void CPlayer::OnCollisionEnter(CCollider* pOtherCollider)
{
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Ground"&&pOtherCollider->GetPos().y>m_vecPos.y)
	{	
		

			islanding = true;
		
	}

	if (pTarget == L"Wall")
	{
		if ((State == PlayerState::Jump || State == PlayerState::Fall || State == PlayerState::Flip))
		{
			State = PlayerState::WallGrab;
			Isgrabed = pOtherCollider;
			WallGrabTimer = 1;
		}
		else
		{

		}
	}
	if (pTarget == L"R_High_Slope")
	{
		
	}
	if (pTarget == L"L_High_Slope")
	{

	}
	if (pTarget == L"Platfoam" && pOtherCollider->GetPos().y > m_vecPos.y)
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

		if((State!=PlayerState::Jump))
		{
		


		Logger::Debug(L"그라운드");

		if ((State == PlayerState::Attack))
		{
			if (m_vecPos.y < pOtherCollider->GetPos().y)//땅밟고 서있기
			{
				islanding = true;
				m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 ;
			}

			else //천장에 머리박기
			{
				m_vecPos.y = pOtherCollider->GetPos().y + pOtherCollider->GetScale().y / 2 + m_vecScale.y / 2;
			}
		}
		else
		{
			if (m_vecPos.y < pOtherCollider->GetPos().y)//땅밟고 서있기
			{
				islanding = true;
				m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 + 2;
			}

			else //천장에 머리박기
			{
				m_vecPos.y = pOtherCollider->GetPos().y + pOtherCollider->GetScale().y / 2 + m_vecScale.y / 2;
			}
		}

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

		if ((State ==PlayerState::WallGrab))
		{
			State = PlayerState::WallGrab;

		}
		else
		{
			if (m_vecPos.x < pOtherCollider->GetPos().x)//왼쪽에서 부딪히기
			{
				m_vecPos.x = pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - m_vecScale.x / 2;
			}
			else//오른쪽에서 부딪히기
			{
				m_vecPos.x = pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + m_vecScale.x / 2;
			}
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
			jumpAction = false;
			islanding = true;
			
		}
	}
	if (pTarget == L"L_High_Slope")
	{	
		float Slope2;
		Slope2 = ((pOtherCollider->GetScale().y / pOtherCollider->GetScale().x) * (m_vecPos.x - pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2) + pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2)-m_vecScale.y/2;
		if (Slope2 < m_vecPos.y)
		{
			m_vecPos.y = Slope2;
			jumpAction = false;
			islanding = true;
			
		}
	}
	if (pTarget == L"Platfoam")
	{
		if (State != PlayerState::Jump&&!BUTTONSTAY(VK_DOWN))
		{
			if (m_vecPos.y + m_vecScale.y / 2 - 1 < pOtherCollider->GetPos().y)//땅밟고 서있기
			{
				islanding = true;
				m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 + 2;
			}
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
		if (State != PlayerState::Jump&&State!=PlayerState::Attack)
		{
			jumpAction = true;
			velocity = -500;
			State = PlayerState::Fall;
		}
	}
}
#pragma endregion
void CPlayer::WhereAmI()
{
	PLAYERPOSITION= m_vecPos;
}

void CPlayer::WhereWasI()
{
	GAME->PrevPlayerPos = m_vecPos;
}

void CPlayer::WhatIsMyState()
{
	GAME->PlayerNowState = State;
}
