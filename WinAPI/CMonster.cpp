#include "framework.h"
#include "CMonster.h"

#include "CRenderManager.h"
#include "CCollider.h"

CMonster::CMonster()
{
	m_vecScale = Vector(100, 60);
	m_strName = L"����";
	m_layer = Layer::Monster;
	//m_vecWhereIsStair = {};
	//m_vecWhereIsStair2 = {};
	m_vecLookDir.x = +1;
	m_bIsMove = false;
	m_bIsDie = false;
	m_fIdleTimer = 16.f;
	m_fWalkTimer = 4.f;

	m_fRange = 0.f;
	m_bPlayerIsSameFloor = false;
	m_mState = MonsterState::Idle;
	m_fSpeed = 300.f;
	m_fDieTimer = 1.f;
	Patroller = false;
	
}

CMonster::~CMonster()
{
}

void CMonster::SetPatroller(bool Patroll)
{
	Patroller = Patroll;
}

void CMonster::SetState(MonsterState state)
{
	m_mState = state;
}

//Vector CMonster::GetStair()
//{
//	return m_vecWhereIsStair;
//}
//
//Vector CMonster::GetStair2()
//{
//	return m_vecWhereIsStair2;
//}
//
//void CMonster::SetStair(Vector Stair)
//{
//	m_vecWhereIsStair = Stair;
//}
//
//void CMonster::SetStair2(Vector Stair)
//{
//	m_vecWhereIsStair2 = Stair;
//}

void CMonster::Init()
{
	AddCollider(ColliderType::Rect, Vector(90, 90), Vector(0, 0));
}

void CMonster::Update()
{	
	
}

void CMonster::Render()
{
	//RENDER->FrameRect(
		//m_vecPos.x - m_vecScale.x * 0.5f,
		//m_vecPos.y - m_vecScale.y * 0.5f,
		//m_vecPos.x + m_vecScale.x * 0.5f,
		//m_vecPos.y + m_vecScale.y * 0.5f);
}

void CMonster::Release()
{
}

void CMonster::DieCount()
{
	GAME->m_iDeadMonster++;
}

void CMonster::VisualSensor()
{
	//�浹ü�� ������ �þ� ����.
	//�ڽ��� �þ������� �簢���� ����
	if (GAME->PlayerNowState != PlayerState::Dance)
	{
		if (m_vecLookDir.x == 1)//������
		{
			if ((PLAYERPOSITION.x > m_vecPos.x) && (PLAYERPOSITION.x < m_vecPos.x + 600) && m_bPlayerIsSameFloor)
			{
				m_mState = MonsterState::Chase;
				Sight();
			}
		}
		else//������
		{
			if ((PLAYERPOSITION.x < m_vecPos.x) && (PLAYERPOSITION.x > m_vecPos.x - 600) && m_bPlayerIsSameFloor)
			{
				m_mState = MonsterState::Chase;
				Sight();
			}
		}
	}

}

void CMonster::Sight()
{
}

void CMonster::AuditorySensor()
{

}

void CMonster::Hearing()
{
}

void CMonster::OnCollisionEnter(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}

	
}

void CMonster::OnCollisionStay(CCollider* pOtherCollider)
{

	wstring pTarget = pOtherCollider->GetObjName();

	if (pTarget == L"Smoke"&&m_layer!=Layer::Corpse)
	{
		m_mState = MonsterState::Attention;
		//����ǥ ����Ʈ
	}


	if (pTarget == L"Ground")
	{
		if (m_vecPos.y < pOtherCollider->GetPos().y)//����� ���ֱ�
		{
			//islanding = true;
			m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 + 2;
		}
	}
	if (pTarget == L"Wall" || pTarget == L"SD" ||pTarget==L"Door")
	{



		if (m_vecPos.x < pOtherCollider->GetPos().x)//���ʿ��� �ε�����
		{
			m_vecPos.x = pOtherCollider->GetPos().x - pOtherCollider->GetScale().x / 2 - m_vecScale.x / 2;
		}
		else//�����ʿ��� �ε�����
		{
			m_vecPos.x = pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2 + m_vecScale.x / 2;
		}
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
		Slope2 = ((pOtherCollider->GetScale().y / pOtherCollider->GetScale().x) * (m_vecPos.x - pOtherCollider->GetPos().x + pOtherCollider->GetScale().x / 2) + pOtherCollider->GetPos().y - pOtherCollider->GetScale().y / 2) - m_vecScale.y / 2;
		if (Slope2 < m_vecPos.y)
		{
			m_vecPos.y = Slope2;
			

		}
	}
	if (pTarget == L"Platfoam")
	{
		
			if (m_vecPos.y + m_vecScale.y / 2 - 1 < pOtherCollider->GetPos().y/*&&m_bEnterStair==false*/)//����� ���ֱ�
			{
				
				m_vecPos.y = pOtherCollider->GetOwner()->GetPos().y - m_vecScale.y / 2 + 2;
			}
		
	}
}

void CMonster::OnCollisionExit(CCollider* pOtherCollider)
{
	if (pOtherCollider->GetObjName() == L"�÷��̾�")
	{
		Logger::Debug(L"���Ͱ� �÷��̾�� �浹����");
	}
	else if (pOtherCollider->GetObjName() == L"�̻���")
	{
		Logger::Debug(L"���Ͱ� �̻��ϰ� �浹����");
	}
}
