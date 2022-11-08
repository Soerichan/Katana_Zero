#include "framework.h"
#include "CR_High_Slope.h"

CR_High_Slope::CR_High_Slope()
{
}

CR_High_Slope::~CR_High_Slope()
{
}

void CR_High_Slope::Init()
{
	CStageObject::Init();
	AddCollider(ColliderType::Rect,
		Vector(m_vecScale),
		Vector(m_vecScale.x / 2, m_vecScale.y / 2));

	m_strName = L"R_High_Slope";
}

void CR_High_Slope::Update()
{
}

void CR_High_Slope::Render()
{
	CStageObject::Render();
	RENDER->Text(L"R_High_Slope", m_vecPos.x, m_vecPos.y, m_vecPos.x + m_vecScale.x, m_vecPos.y + m_vecScale.y);
	ComponentRender();
}

void CR_High_Slope::Release()
{
}

void CR_High_Slope::OnCollisionEnter(CCollider* pOther)
{
}

void CR_High_Slope::OnCollisionStay(CCollider* pOther)
{
}

void CR_High_Slope::OnCollisionExit(CCollider* pOther)
{
}
