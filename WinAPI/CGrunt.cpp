#include "framework.h"
#include "CGrunt.h"

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
	//m_pIdleImage = RESOURCE->LoadImg(L"GruntIdle", L"Image\\GRUNT\\idle.png");
	m_pAnimator = new CAnimator;



	m_pAnimator->CreateAnimation(L"GruntIdleRight", m_pIdleImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);
	m_pAnimator->CreateAnimation(L"GruntIdleLeft", m_pIdleImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8);

	m_pAnimator->CreateAnimation(L"GruntWalkRight", m_pWalkImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);
	m_pAnimator->CreateAnimation(L"GruntWalkLeft", m_pWalkImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);

	m_pAnimator->CreateAnimation(L"GruntRunRight", m_pRunImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);
	m_pAnimator->CreateAnimation(L"GruntRunLeft", m_pRunImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 10);

	m_pAnimator->CreateAnimation(L"GruntAttackRight", m_pAttackImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8, false);
	m_pAnimator->CreateAnimation(L"GruntAttackLeft", m_pAttackImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 8, false);

	m_pAnimator->CreateAnimation(L"GruntDieRight", m_pDieImage, Vector(0.f, 0.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);
	m_pAnimator->CreateAnimation(L"GruntDieLeft", m_pDieImage, Vector(0.f, 300.f), Vector(200.f, 200.f), Vector(300.f, 0.f), 0.1f, 15, false);

	m_pAnimator->Play(L"GruntIdleRight", false);
	AddComponent(m_pAnimator);

	//AddCollider(ColliderType::Rect, Vector(, 55), Vector(0, 0));

	m_vecLookDir.x = -1;
	m_vecLookDir.y = +1;
	m_fRange = 25.f;
}

void CGrunt::Update()
{	
	CMonster::Update();

	if (m_bIsDie == false)
	{
		
		m_vecPos.y += 0.8f;
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
			str += L"Walk";
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
	
}