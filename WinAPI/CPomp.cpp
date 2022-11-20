#include "framework.h"
#include "CPomp.h"
#include "CPompSlash.h"
#include "CBluntEffect.h"


void CPomp::Init()
{
	CMonster::Init();
	m_pIdleImage = RESOURCE->LoadImg(L"PompIdle", L"Image\\Pomp\\IDLE\\IDLE.png");
	m_pWalkImage = RESOURCE->LoadImg(L"PompWalk", L"Image\\Pomp\\WALK\\WALK.png");
	m_pRunImage = RESOURCE->LoadImg(L"PompRun", L"Image\\Pomp\\RUN\\RUN.png");
	m_pAttackImage = RESOURCE->LoadImg(L"PompAttack", L"Image\\Pomp\\ATTACK\\ATTACK.png");
	m_pDieImage = RESOURCE->LoadImg(L"PompDie", L"Image\\Pomp\\DIE\\DIE.png");
	m_pDownImage = RESOURCE->LoadImg(L"PompDown", L"Image\\Pomp\\Down\\Down.png");
	m_pStandUpImage = RESOURCE->LoadImg(L"PompStandUp", L"Image\\Pomp\\STANDUP\\STANDUP.png");
	m_pAnimator = new CAnimator;



	m_pAnimator->CreateAnimation(L"PompIdleRight", m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"PompIdleLeft", m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	m_pAnimator->CreateAnimation(L"PompWalkRight", m_pWalkImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);
	m_pAnimator->CreateAnimation(L"PompWalkLeft", m_pWalkImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);

	m_pAnimator->CreateAnimation(L"PompRunRight", m_pRunImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);
	m_pAnimator->CreateAnimation(L"PompRunLeft", m_pRunImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);

	m_pAnimator->CreateAnimation(L"PompAttackRight", m_pAttackImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6, false);
	m_pAnimator->CreateAnimation(L"PompAttackLeft", m_pAttackImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6, false);

	m_pAnimator->CreateAnimation(L"PompDownRight", m_pDownImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10, false);
	m_pAnimator->CreateAnimation(L"PompDownLeft", m_pDownImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10, false);


	m_pAnimator->CreateAnimation(L"PompStandUpRight", m_pStandUpImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11, false);
	m_pAnimator->CreateAnimation(L"PompStandUpLeft", m_pStandUpImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 11, false);

	m_pAnimator->CreateAnimation(L"PompDieRight", m_pDieImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5, false);
	m_pAnimator->CreateAnimation(L"PompDieLeft", m_pDieImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 5, false);

	m_pAnimator->Play(L"PompIdleRight", false);
	AddComponent(m_pAnimator);

	//AddCollider(ColliderType::Rect, Vector(, 55), Vector(0, 0));

	m_vecLookDir.x = -1;
	m_vecLookDir.y = +1;
	m_fRange = 50.f;
	m_fAimTimer = 0.4f;
	m_fAttackTimer = 0.6f;
	m_fAfterAttackTimer = 0.f;
	m_fDownTimer = 1.0f;
	m_fStandUpTimer = 1.1f;
	m_fDisapearTimer = 0.01f;
}

void CPomp::Update()
{
	
	
	m_vecPos.y += 1.f;//기본중력

		m_vecWhereIsPlayer = PLAYERPOSITION;//플레이어의 위치를 계속 수신한다

		if ((PLAYERPOSITION.y > m_vecPos.y - 30) && (PLAYERPOSITION.y < m_vecPos.y + 30))//플레이어와 같은 층인지 확인한다
		{
			m_bPlayerIsSameFloor = true;
		}
		else
		{
			m_bPlayerIsSameFloor = false;
		}

		if (m_mState == MonsterState::Idle && !Patroller)
		{
			m_fIdleTimer -= DT;
			VisualSensor();

			if (m_fIdleTimer >= 12.f)
			{
				m_bIsMove = false;

			}
			else if (m_fIdleTimer >= 8.f && m_fIdleTimer <= 12.f)
			{
				m_vecLookDir.x = +1;
				m_vecPos.x += 0.5f * m_fSpeed * DT;
				m_bIsMove = true;
			}
			else if (m_fIdleTimer >= 4.f && m_fIdleTimer <= 8.f)
			{
				m_bIsMove = false;
			}
			else if (m_fIdleTimer >= 0.f && m_fIdleTimer <= 4.f)
			{
				m_vecLookDir.x = -1;
				m_vecPos.x -= 0.5f * m_fSpeed * DT;
				m_bIsMove = true;
			}
			else
			{
				m_fIdleTimer = 16.f;
			}
		}

		if (m_mState == MonsterState::Chase)
		{
			m_fAttackTimer = 0.6f;
			m_bIsMove = true;
			m_fAfterAttackTimer -= DT;

		/*	if (m_bPlayerIsSameFloor == true)
			{*/
				if (PLAYERPOSITION.x < m_vecPos.x)
				{
					m_vecLookDir.x = -1;
					m_vecPos.x -= m_fSpeed * 2 * DT;
				}
				else
				{
					m_vecLookDir.x = +1;
					m_vecPos.x += m_fSpeed * 2 * DT;
				}

				if ((abs(PLAYERPOSITION.x - m_vecPos.x) <= m_fRange) && m_bPlayerIsSameFloor && m_fAfterAttackTimer <= 0)
				{
					m_mState = MonsterState::Attack;
					Attack();
				}
			/*}*/
			/*else
			{
				if (m_bEnterStair == false)
				{
					if (m_vecWhereIsStair.x < m_vecPos.x)
					{
						m_vecLookDir.x = -1;
						m_vecPos.x -= m_fSpeed * 2 * DT;

						if (m_vecWhereIsStair.x > m_vecPos.x - 10.f)
						{
							m_bEnterStair = true;
						}
					}
					else
					{
						m_vecLookDir.x = 1;
						m_vecPos.x += m_fSpeed * 2 * DT;

						if (m_vecWhereIsStair.x < m_vecPos.x + 10.f)
						{
							m_bEnterStair = true;
						}
					}

				}
				else
				{
					
					if (PLAYERPOSITION.x < m_vecPos.x)
					{
						m_vecLookDir.x = -1;
						m_vecPos.x -= m_fSpeed * 2 * DT;
					}
					else
					{
						m_vecLookDir.x = +1;
						m_vecPos.x += m_fSpeed * 2 * DT;
					}

					if ((abs(PLAYERPOSITION.x - m_vecPos.x) <= m_fRange) && m_bPlayerIsSameFloor && m_fAfterAttackTimer <= 0)
					{
						m_mState = MonsterState::Attack;
						Attack();
					}
				}
			}*/
		}

	

		if (m_mState == MonsterState::Attack)
		{
			m_fAttackTimer -= DT;

			if (m_fAttackTimer <= 0)
			{
				
				m_fAfterAttackTimer = 0.4f;
				m_mState = MonsterState::Chase;
			}
		}


	
		if (m_mState == MonsterState::Down)
		{

			if (m_fDownTimer >= 0)
			{
				m_fDownTimer -= DT;

				if (GAME->RightAttack == true)
				{
					m_vecPos.x += 800 * m_fDownTimer * m_fDownTimer * DT;
				}
				else
				{
					m_vecPos.x -= 800 * m_fDownTimer * m_fDownTimer * DT;
				}

			}
			else
			{

				if (m_bIsDie == true)
				{
					m_mState = MonsterState::Die;
				}
				else
				{	
					m_fDownTimer = 1.0f;
					m_mState = MonsterState::StandUp;
				}
			}
		}

		if (m_mState == MonsterState::StandUp)
		{
			m_fStandUpTimer -= DT;

			if (m_fStandUpTimer <= 0)
			{
				m_mState = MonsterState::Chase;
				m_fStandUpTimer = 1.0f;
			}
		}
	
		if (m_mState == MonsterState::Die)
		{
			m_fDisapearTimer -= DT;
			if (m_fDisapearTimer <= 0)
			{
				m_layer = Layer::Corpse;
			}
		}


	AnimatorUpdate();
}


void CPomp::Render()
{
}

void CPomp::Release()
{
}

void CPomp::AnimatorUpdate()
{
	wstring str = L"Pomp";

	switch (m_mState)
	{
	case MonsterState::Idle:
		if (m_bIsMove == false)
		{
			str += L"Idle";
		}
		else
		{
			str += L"Walk";
		}
		break;
	case MonsterState::Attention:
		if (m_bIsMove == false)
		{
			str += L"Idle";
		}
		else
		{
			str += L"Run";
		}
		break;
	case MonsterState::Chase:
		str += L"Run";
		break;
	case MonsterState::Attack:
		str += L"Attack";
		break;
	case MonsterState::Aim:
		break;
	case MonsterState::Fire:
		break;
	case MonsterState::Down:
		str += L"Down";
		break;
	case MonsterState::StandUp:
		str += L"StandUp";
		break;
	case MonsterState::Laser:
		break;
	case MonsterState::Die:
		str += L"Die";
		break;
	
	}
	if (m_vecLookDir.x == +1)
	{
		str += L"Right";
	}
	else
	{
		str += L"Left";
	}

	m_pAnimator->Play(str, false);
}

void CPomp::OnCollisionEnter(CCollider* pOtherCollider)
{
	CMonster::OnCollisionEnter(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Laser" || pTarget == L"Door"|| pOtherCollider->GetOwner()->GetLayer()==Layer::Missile	)
	{
		if (m_mState != MonsterState::Attack)
		{
			if (m_bIsDie == false)
			{

				
				m_bIsDie = true;
			}
		}
		else
		{
			CBluntEffect* pBluntEffect = new CBluntEffect;
			if (GAME->RightAttack)
			{
				pBluntEffect->SetPos(m_vecPos.x+60,m_vecPos.y);
			}
			else
			{
				pBluntEffect->SetPos(m_vecPos.x -60, m_vecPos.y);
			}
			
			ADDOBJECT(pBluntEffect);
		}
	
		m_mState = MonsterState::Down;
	}

	
}

void CPomp::OnCollisionStay(CCollider* pOtherCollider)
{
	CMonster::OnCollisionStay(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	/*if (pTarget == L"KatanaSlash")
	{
		if (m_bIsDie == false)
		{
			m_mState = MonsterState::Die;
			m_bIsDie = true;
		}
	}*/
}

void CPomp::OnCollisionExit(CCollider* pOtherCollider)
{
}


CPomp::CPomp()
{
}

CPomp::~CPomp()
{
}

void CPomp::Attack()
{
	CPompSlash* pCPompSlash = new CPompSlash;

	if (m_vecLookDir.x == +1)
	{
		pCPompSlash->SetDir(1);
		pCPompSlash->SetPos(m_vecPos.x + 5, m_vecPos.y - 20);
	}
	else
	{
		pCPompSlash->SetDir(0);
		pCPompSlash->SetPos(m_vecPos.x - 5, m_vecPos.y - 20);
	}
	ADDOBJECT(pCPompSlash);
}