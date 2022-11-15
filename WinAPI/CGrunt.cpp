#include "framework.h"
#include "CGrunt.h"
#include"CGruntSlash.h"

CGrunt::CGrunt()
{
}

CGrunt::~CGrunt()
{
}


void CGrunt::Init()
{	
	CMonster::Init();
	m_pIdleImage = RESOURCE->LoadImg(L"GruntIdle", L"Image\\GRUNT\\idle\\IDLE.png");
	m_pWalkImage = RESOURCE->LoadImg(L"GruntWalk", L"Image\\GRUNT\\walk\\WALK.png");
	m_pRunImage = RESOURCE->LoadImg(L"GruntRun", L"Image\\GRUNT\\run\\RUN.png");
	m_pAttackImage = RESOURCE->LoadImg(L"GrunAttack", L"Image\\GRUNT\\attack\\ATTACK.png");
	m_pDieImage = RESOURCE->LoadImg(L"GruntDie", L"Image\\GRUNT\\die\\DIE.png");
	m_pAimImage = RESOURCE->LoadImg(L"GruntAim", L"Image\\GRUNT\\aim\\AIM.png");
	m_pAnimator = new CAnimator;



	m_pAnimator->CreateAnimation(L"GruntIdleRight", m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"GruntIdleLeft", m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	m_pAnimator->CreateAnimation(L"GruntWalkRight", m_pWalkImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);
	m_pAnimator->CreateAnimation(L"GruntWalkLeft", m_pWalkImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);

	m_pAnimator->CreateAnimation(L"GruntRunRight", m_pRunImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);
	m_pAnimator->CreateAnimation(L"GruntRunLeft", m_pRunImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);

	m_pAnimator->CreateAnimation(L"GruntAttackRight", m_pAttackImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	m_pAnimator->CreateAnimation(L"GruntAttackLeft", m_pAttackImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);

	m_pAnimator->CreateAnimation(L"GruntAimRight", m_pAimImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);
	m_pAnimator->CreateAnimation(L"GruntAimLeft", m_pAimImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 4, false);


	m_pAnimator->CreateAnimation(L"GruntDieRight", m_pDieImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);
	m_pAnimator->CreateAnimation(L"GruntDieLeft", m_pDieImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);

	m_pAnimator->Play(L"GruntIdleRight", false);
	AddComponent(m_pAnimator);

	//AddCollider(ColliderType::Rect, Vector(, 55), Vector(0, 0));

	m_vecLookDir.x = -1;
	m_vecLookDir.y = +1;
	m_fRange = 35.f;
	m_fAimTimer = 0.4f;
	m_fAttackTimer = 0.4f;
	m_fAfterAttackTimer = 0.f;
}

void CGrunt::Update()
{	
	
	if (m_bIsDie == false)
	{
			
		m_vecPos.y += 0.8f;//기본중력

		m_vecWhereIsPlayer = PLAYERPOSITION;//플레이어의 위치를 계속 수신한다

		if ((PLAYERPOSITION.y > m_vecPos.y - 30) && (PLAYERPOSITION.y < m_vecPos.y + 30))//플레이어와 같은 층인지 확인한다
		{
			m_bPlayerIsSameFloor = true;
		}
		else
		{
			m_bPlayerIsSameFloor = false;
		}

		if (m_mState == MonsterState::Idle)
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
			m_fAttackTimer = 2.f;
			m_bIsMove = true;
			m_fAfterAttackTimer -= DT;

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

			if ((abs(PLAYERPOSITION.x - m_vecPos.x) <= m_fRange) && m_bPlayerIsSameFloor&&m_fAfterAttackTimer<=0)
			{
				m_mState = MonsterState::Aim;
				
			}
		}

		if (m_mState == MonsterState::Aim)
		{
			m_fAimTimer -= DT;

			
				if (m_fAimTimer <= 0)
				{
					
					Attack();
					m_fAttackTimer = 0.4f;
					m_mState = MonsterState::Attack;
				}
			
		}

		if (m_mState == MonsterState::Attack)
		{
			m_fAttackTimer -= DT;

			if (m_fAttackTimer <= 0)
			{	
				m_fAimTimer = 0.4f;
				m_fAfterAttackTimer = 0.4f;
				m_mState = MonsterState::Chase;
			}
		}

	
	}
	else
	{


		if (m_fDieTimer >= 0)
		{
			m_fDieTimer -= DT;

			if (GAME->RightAttack == true)
			{
				m_vecPos.x += 800 * m_fDieTimer * m_fDieTimer * DT;
			}
			else
			{
				m_vecPos.x -= 800 * m_fDieTimer * m_fDieTimer * DT;
			}
		}

	}


	AnimatorUpdate();
}

void CGrunt::Render()
{
}

void CGrunt::Release()
{
}

void CGrunt::AnimatorUpdate()
{
	wstring str = L"Grunt";
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
	case MonsterState::Aim:
		str += L"Aim";
		break;
	case MonsterState::Attack:
		str += L"Attack";
		break;
	case MonsterState::Fire:
		str += L"Attack";
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

void CGrunt::OnCollisionEnter(CCollider* pOtherCollider)
{
	CMonster::OnCollisionEnter(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"KatanaSlash")
	{
		if (m_bIsDie == false)
		{	

			m_mState = MonsterState::Die;
			m_bIsDie = true;
		}
	}

}

void CGrunt::OnCollisionStay(CCollider* pOtherCollider)
{
	CMonster::OnCollisionStay(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"KatanaSlash")
	{
		if (m_bIsDie == false)
		{
			m_mState = MonsterState::Die;
			m_bIsDie = true;
		}
	}
}

void CGrunt::OnCollisionExit(CCollider* pOtherCollider)
{
	CMonster::OnCollisionExit(pOtherCollider);
}


void CGrunt::Attack()
{
	CGruntSlash* pCGruntSlash = new CGruntSlash;
	
	if (m_vecLookDir.x == +1)
	{
		pCGruntSlash->SetDir(1);
		pCGruntSlash->SetPos(m_vecPos.x+5,m_vecPos.y-20);
	}
	else
	{
		pCGruntSlash->SetDir(0);
		pCGruntSlash->SetPos(m_vecPos.x - 5, m_vecPos.y - 20);
	}
		ADDOBJECT(pCGruntSlash);
}