#include "framework.h"
#include "CSubWeapon.h"

CSubWeapon::CSubWeapon()
{
	m_layer = Layer::SubWeapon;
	m_strName = L"SubWeapon";
}

CSubWeapon::~CSubWeapon()
{
}

void CSubWeapon::SetDir(Vector dir)
{
	m_vecDir = dir;
}

void CSubWeapon::Init()
{
	if (m_layer == Layer::Missile)
	{
		AddCollider(ColliderType::Rect, Vector(50, 50), Vector(0, 0));
	}
	m_vecScale = Vector(m_pImage->GetWidth(), m_pImage->GetHeight());
}

void CSubWeapon::Update()
{
	if (m_layer == Layer::Missile)
	{

		m_vecPos += m_vecDir * 500 * DT;
		m_fDegree += 700*DT;
		/*if (GAME->RightAttack)
		{
			m_vecPos.x += 300  * DT;
		}
		else
		{
			m_vecPos.x -= 300  * DT;

		}*/
	}
}

void CSubWeapon::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(
			m_pImage,
			m_vecPos.x - m_vecScale.x * 0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
			, 1.f, m_fDegree
		);
	}
}

void CSubWeapon::Release()
{
}

void CSubWeapon::OnCollisionEnter(CCollider* pOtherCollider)
{
	DELETEOBJECT(this);
}
