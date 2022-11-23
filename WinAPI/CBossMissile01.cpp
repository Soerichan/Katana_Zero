#include "framework.h"
#include "CBossMissile01.h"

CBossMissile01::CBossMissile01()
{
	m_layer = Layer::EnemyMissile;
}

CBossMissile01::~CBossMissile01()
{
}

void CBossMissile01::AnimatorUpdate()
{
}

void CBossMissile01::Init()
{
	//m_layer = Layer::EnemyMissile;
	m_strName = L"Axe";
	m_vecScale = Vector(26, 80);
	m_pImage= RESOURCE->LoadImg(L"AxeThrow", L"Image\\Boss\\spr_kissyface_axe_0.png");
	m_fTimer = 4.f;
	accel = 100;
	velocity = 100;
	AddCollider(ColliderType::Circle, Vector(35, 35), Vector(0, 0));
}

void CBossMissile01::Update()
{
	//m_layer = Layer::EnemyMissile;
	m_fTimer -= DT;
	m_fDegree += 700 * DT;

	if (m_fTimer >= 2.f)
	{
		if (m_vecDir.x == 1)
		{
			m_vecPos.x += 300 * DT;
		}
		else
		{
			m_vecPos.x -= 300 * DT;
		}
	}
	else if (m_fTimer < 2.f && m_fTimer >= 0)
	{
		if (m_vecDir.x == 1)
		{
			m_vecPos.x -= 300 * DT;
		}
		else
		{
			m_vecPos.x += 300 * DT;
		}
	}
	else
	{
		DELETEOBJECT(this);
	}
	
}

void CBossMissile01::Render()
{
	RENDER->Image(m_pImage, m_vecPos.x - m_vecScale.x *0.5f, m_vecPos.y - m_vecScale.y * 0.5f, m_vecPos.x + m_vecScale.x * 0.5f, m_vecPos.y + m_vecScale.y * 0.5f, 1.f, m_fDegree);
}

void CBossMissile01::Release()
{
}
