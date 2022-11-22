#include "framework.h"
#include "CSubWeapon.h"
#include "CSmoke.h"

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
	m_pSound= RESOURCE->LoadSound(L"SubWeaponSound", L"Sound\\CrushGlass.wav");
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
	wstring pTarget = pOtherCollider->GetObjName();
	if (pOtherCollider->GetOwner()->GetLayer() != Layer::Corpse||pTarget!=L"Platfoam")
	{
		if (m_strName == L"Smoker")
		{
			CSmoke* pSmoke0 = new CSmoke;
			pSmoke0->SetPos(m_vecPos.x , m_vecPos.y );
			ADDOBJECT(pSmoke0);
		}
		SOUND->Play(m_pSound, 0.6f);
		DELETEOBJECT(this);
	}
}
