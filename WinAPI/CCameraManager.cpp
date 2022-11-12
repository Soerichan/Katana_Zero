#include "framework.h"
#include "CCameraManager.h"

#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CGameObject.h"

CCameraManager::CCameraManager()
{
	m_vecLookAt		= Vector(0, 0);
	m_vecTargetPos	= Vector(0, 0);
	m_pTargetObj	= nullptr;
	m_fTimeToTarget = 0;

	m_fTargetBright = 1.f;
	m_fCurBright = 1.f;
	m_fTimeToBright = 0.f;

	Focus = {};

	readyTimer = 0;
}

CCameraManager::~CCameraManager()
{
}

Vector CCameraManager::GetLookAt()
{
	return m_vecLookAt;
}

Vector CCameraManager::GetTargetPos()
{
	return m_vecTargetPos;
}

CGameObject* CCameraManager::GetTargetObj()
{
	return m_pTargetObj;
}

void CCameraManager::SetTargetPos(Vector targetPos, float timeToTarget)
{
	m_vecTargetPos = targetPos;
	m_fTimeToTarget = timeToTarget;
}

void CCameraManager::SetTargetObj(CGameObject* pTargetObj)
{
	m_pTargetObj = pTargetObj;
}

Vector CCameraManager::WorldToScreenPoint(Vector worldPoint)
{
	return worldPoint - (m_vecLookAt - Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));
}

Vector CCameraManager::ScreenToWorldPoint(Vector screenPoint)
{
	return screenPoint + (m_vecLookAt - Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));
}

void CCameraManager::Scroll(Vector dir, float velocity)
{
	// ��ũ���� ���� ũ�Ⱑ ���� ��� �������� ����
	if (dir.Magnitude() == 0)
		return;

	// ��ũ���� ��ǥ ��ġ�� ������ġ���� ��ũ�� �������� ������ ��ġ
	m_vecTargetPos = m_vecLookAt;
	m_vecTargetPos += dir.Normalized() * velocity * DT;
	m_fTimeToTarget = 0;	// ��ũ���� �ð����� ���� ���� �ﰢ �̵�
}

void CCameraManager::CameraWalk()
{	
	Vector Player = PLAYERPOSITION;
	Vector Cursor = MOUSEWORLDPOS;
	Vector PreFocus = {};

	PreFocus.x = (Cursor.x + Player.x) * 0.5f;
	PreFocus.y = (Player.y + Cursor.y) * 0.5f;



	if (GAME->PlayerNowState == PlayerState::Idle)
	{	
		
		if (PreFocus.x + (WINSIZEX * 0.5) > SCENE->GetCurScene()->m_pbackGround->GetImage()->GetWidth() - 2)
		{
			PreFocus.x = SCENE->GetCurScene()->m_pbackGround->GetImage()->GetWidth() - (WINSIZEX * 0.5) - 2;
		}

		if (PreFocus.y + (WINSIZEY * 0.5) > SCENE->GetCurScene()->m_pbackGround->GetImage()->GetHeight() - 2)
		{
			PreFocus.y = SCENE->GetCurScene()->m_pbackGround->GetImage()->GetHeight() - (WINSIZEY * 0.5) - 2;
		}

		if (PreFocus.x - (WINSIZEX * 0.5) < 2)
		{
			PreFocus.x = 2 + (WINSIZEX * 0.5);
		}

		if (PreFocus.y - (WINSIZEY * 0.5) < 2)
		{
			PreFocus.y = 2 + (WINSIZEY * 0.5);
		}
		Focus = PreFocus;
		SetTargetPos(Focus, 1.f);
	}
	else
	{
		while (abs(Player.x - PreFocus.x) > 30)
		{
			PreFocus.x = (PreFocus.x + Player.x) * 0.5f;
			
		}

		while (abs(Player.y - PreFocus.y) > 30)
		{
			
			PreFocus.y = (PreFocus.y + Player.y) * 0.5f;
		}

		if (PreFocus.x + (WINSIZEX * 0.5) > SCENE->GetCurScene()->m_pbackGround->GetImage()->GetWidth() - 2)
		{
			PreFocus.x = SCENE->GetCurScene()->m_pbackGround->GetImage()->GetWidth() - (WINSIZEX * 0.5) - 2;
		}

		if (PreFocus.y + (WINSIZEY * 0.5) > SCENE->GetCurScene()->m_pbackGround->GetImage()->GetHeight() - 2)
		{
			PreFocus.y = SCENE->GetCurScene()->m_pbackGround->GetImage()->GetHeight() - (WINSIZEY * 0.5) - 2;
		}

		if (PreFocus.x - (WINSIZEX * 0.5) < 2)
		{
			PreFocus.x = 2 + (WINSIZEX * 0.5);
		}

		if (PreFocus.y - (WINSIZEY * 0.5) < 2)
		{
			PreFocus.y = 2+ (WINSIZEY * 0.5);
		}

		Focus = PreFocus;
		SetTargetPos(Focus, 0.1f);
	}


	

	
}

void CCameraManager::FadeIn(float duration)
{
	m_fTargetBright = 1.f;
	m_fTimeToBright = duration;
}

void CCameraManager::FadeOut(float duration)
{
	m_fTargetBright = 0.f;
	m_fTimeToBright = duration;
}

void CCameraManager::Init()
{
}

void CCameraManager::Update()
{
	// ������ ���ӿ�����Ʈ�� ���� ���
	if (nullptr != m_pTargetObj)
	{
		if (m_pTargetObj->GetReserveDelete())
		{
			// ������ ���ӿ�����Ʈ�� ���������� ��� ���� ����
			m_pTargetObj = nullptr;
		}
		else
		{
			// ������ ���ӿ�����Ʈ�� ���� ��� ���ӿ�����Ʈ�� ��ġ�� ��ǥ��ġ�� ����
			SetTargetPos(m_pTargetObj->GetPos());
		}
	}

	// ��ǥ ��ġ�� �̵�
	MoveToTarget();
}

void CCameraManager::Render()
{
	RenderEffect();

	Vector screenPos = ScreenToWorldPoint(Vector(0, 0));
	RENDER->FillRect(screenPos.x, screenPos.y, screenPos.x + WINSIZEX, screenPos.y + WINSIZEY, Color(0, 0, 0, 1 - m_fCurBright));
}

void CCameraManager::Release()
{
}

void CCameraManager::MoveToTarget()
{
	m_fTimeToTarget -= DT;

	if (m_fTimeToTarget <= 0)
	{
		// ��ǥ��ġ���� ���� �ð��� ���� ��� �������� ������ġ ����
		m_vecLookAt = m_vecTargetPos;
	}
	else
	{
		// ��ǥ��ġ���� ���� �ð��� ���� ���
		// ���������� �����ð���ŭ�� �ӵ��� �̵�
		// �̵��Ÿ� = �ӷ� * �ð�
		// �ӷ� = (������ - �����) / �ҿ�ð�
		// �ð� = �����Ӵ����ð�
		m_vecLookAt += (m_vecTargetPos - m_vecLookAt) / m_fTimeToTarget * DT;
	}
}

void CCameraManager::RenderEffect()
{
	m_fTimeToBright -= DT;

	if (m_fTimeToBright <= 0)
	{
		// ī�޶� ȿ���� ���� �ð��� ���� ��� ��ǥ ���� ����
		m_fCurBright = m_fTargetBright;
	}
	else
	{
		m_fCurBright += (m_fTargetBright - m_fCurBright) / m_fTimeToBright * DT;
	}
}
