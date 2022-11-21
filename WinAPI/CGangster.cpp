#include "framework.h"
#include "CGangster.h"
#include "CBullet.h"
#include"CGunSpark.h"

CGangster::CGangster()
{
	m_pIdleImage = nullptr;
	m_pWalkImage = nullptr;
	m_pRunImage = nullptr;
	m_pDieImage = nullptr;
	m_pAnimator = nullptr;
	m_fDisapearTimer = 0.01f;
}

CGangster::~CGangster()
{
}

void CGangster::SetReverse(bool Reverse)
{
	m_bReverse = Reverse;
}

void CGangster::Init()
{
	CMonster::Init();
	m_pIdleImage = RESOURCE->LoadImg(L"GangsterIdle", L"Image\\GANGSTER\\IDLE\\IDLE.png");
	m_pWalkImage = RESOURCE->LoadImg(L"GangsterWalk", L"Image\\GANGSTER\\WALK\\WALK.png");
	m_pRunImage = RESOURCE->LoadImg(L"GangsterRun", L"Image\\GANGSTER\\RUN\\RUN.png");
	//m_pAttackImage = RESOURCE->LoadImg(L"GangsterAttack", L"Image\\GANGSTER\\ATTACK\\ATTACK.png");
	m_pDieImage = RESOURCE->LoadImg(L"GangsterDie", L"Image\\GANGSTER\\DIE\\DIE.png");
	
	m_pAnimator = new CAnimator;



	m_pAnimator->CreateAnimation(L"GangsterIdleRight", m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"GangsterIdleLeft", m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	m_pAnimator->CreateAnimation(L"GangsterWalkRight", m_pWalkImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"GangsterWalkLeft", m_pWalkImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	m_pAnimator->CreateAnimation(L"GangsterRunRight", m_pRunImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);
	m_pAnimator->CreateAnimation(L"GangsterRunLeft", m_pRunImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.08f, 10);

//	m_pAnimator->CreateAnimation(L"GangsterAttackRight", m_pAttackImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6, false);
//	m_pAnimator->CreateAnimation(L"GangsterAttackLeft", m_pAttackImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 6, false);

	m_pAnimator->CreateAnimation(L"GangsterDieRight", m_pDieImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 14, false);
	m_pAnimator->CreateAnimation(L"GangsterDieLeft", m_pDieImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 14, false);

	m_pAnimator->Play(L"GangsterIdleRight", false);
	AddComponent(m_pAnimator);

	//AddCollider(ColliderType::Rect, Vector(, 55), Vector(0, 0));

	m_vecLookDir.x = -1;
	m_vecLookDir.y = +1;
	m_fRange = 500.f;
	m_fAimTimer = 0.1f;
	m_fAttackTimer = 0.1f;
	m_fAfterAttackTimer = 0.1f;
	m_iBulletCount = 0;

}

void CGangster::Update()
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

	if (m_bReverse == false)
	{
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
	}
	else
	{
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
				m_vecLookDir.x = -1;
				m_vecPos.x -= 0.5f * m_fSpeed * DT;
				m_bIsMove = true;
			}
			else if (m_fIdleTimer >= 4.f && m_fIdleTimer <= 8.f)
			{
				m_bIsMove = false;
			}
			else if (m_fIdleTimer >= 0.f && m_fIdleTimer <= 4.f)
			{
				m_vecLookDir.x = +1;
				m_vecPos.x += 0.5f * m_fSpeed * DT;
				m_bIsMove = true;
			}
			else
			{
				m_fIdleTimer = 16.f;
			}
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
			m_mState = MonsterState::Aim;
			
		}
	}

	if (m_mState == MonsterState::Aim)
	{
		m_fAimTimer -= DT;


		if (m_fAimTimer <= 0)
		{

			Attack();
			m_iBulletCount++;
			m_fAttackTimer = 0.1f;
			m_mState = MonsterState::Attack;
		}

	}

	if (m_mState == MonsterState::Attack)
	{
		m_fAttackTimer -= DT;

		if (m_fAttackTimer <= 0)
		{
			m_fAimTimer = 0.5f;
			m_fAfterAttackTimer = 0.1f;
			if (m_iBulletCount > 3)
			{	
				m_iBulletCount = 0;
				m_mState = MonsterState::Chase;
			}
			else
			{
				m_mState = MonsterState::Aim;
			}
		}
	}



	
	if(m_mState==MonsterState::Die)

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

void CGangster::Render()
{
}

void CGangster::Release()
{
}

void CGangster::AnimatorUpdate()
{
	wstring str = L"Gangster";
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
			str += L"Idle";
		break;
	case MonsterState::Chase:
		str += L"Run";
		break;
	case MonsterState::Aim:
		str += L"Idle";
		break;
	case MonsterState::Attack:
		str += L"Idle";
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



void CGangster::Attack()
{	
	CGunSpark* pGunSpark = new CGunSpark;
	if (m_vecLookDir.x == +1)
	{
		pGunSpark->SetPos(m_vecPos.x+80, m_vecPos.y - 15);
		pGunSpark->SetxDir(true);

	}
	else
	{
		pGunSpark->SetPos(m_vecPos.x -80, m_vecPos.y - 15);
		pGunSpark->SetxDir(false);

	}
	ADDOBJECT(pGunSpark);


	CBullet* pBullet = new CBullet;
	pBullet->SetPos(m_vecPos.x, m_vecPos.y - 15);
	if (m_vecLookDir.x == +1)
	{
		pBullet->SetxDir(1);
		
	}
	else
	{
		pBullet->SetxDir(0);
		
	}
	ADDOBJECT(pBullet);
}


void CGangster::OnCollisionEnter(CCollider* pOtherCollider)
{
	CMonster::OnCollisionEnter(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Laser" || pOtherCollider->GetOwner()->GetLayer() == Layer::Missile)
	{
		if (m_bIsDie == false)
		{

			m_mState = MonsterState::Die;
			m_bIsDie = true;
		}
	}
}

void CGangster::OnCollisionStay(CCollider* pOtherCollider)
{
	CMonster::OnCollisionStay(pOtherCollider);
	wstring pTarget = pOtherCollider->GetObjName();

	if (pOtherCollider->GetOwner()->GetLayer()==Layer::Missile)
	{
		if (m_bIsDie == false)
		{
			m_mState = MonsterState::Die;
			RemoveCollider();
			m_bIsDie = true;
		}
	}
}

void CGangster::OnCollisionExit(CCollider* pOtherCollider)
{
}
