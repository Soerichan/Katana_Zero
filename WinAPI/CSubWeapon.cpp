#include "framework.h"
#include "CSubWeapon.h"

CSubWeapon::CSubWeapon()
{
	m_layer = Layer::Effect;
	m_strName = L"SubWeapon";
}

CSubWeapon::~CSubWeapon()
{
}

void CSubWeapon::Init()
{
	//AddCollider(ColliderType::Rect, Vector(48, 96), Vector(0, 0));
}

void CSubWeapon::Update()
{
}

void CSubWeapon::Render()
{
	if (nullptr != m_pImage)
	{
		RENDER->Image(
			m_pImage,
			m_vecPos.x-m_vecScale.x*0.5f,
			m_vecPos.y - m_vecScale.y * 0.5f,
			m_vecPos.x + m_vecScale.x * 0.5f,
			m_vecPos.y + m_vecScale.y * 0.5f
		);
	}
}

void CSubWeapon::Release()
{
}
