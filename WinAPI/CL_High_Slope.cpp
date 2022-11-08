#include "framework.h"
#include "CL_High_Slope.h"

CL_High_Slope::CL_High_Slope()
{
}

CL_High_Slope::~CL_High_Slope()
{
}

void CL_High_Slope::Init()
{
	CStageObject::Init();
	AddCollider(ColliderType::Rect,
		Vector(m_vecScale),
		Vector(m_vecScale.x / 2, m_vecScale.y / 2));

	m_strName = L"L_High_Slope";
}

void CL_High_Slope::Update()
{
}

void CL_High_Slope::Render()
{
	CStageObject::Render();
	RENDER->Text(L"L_High_Slope", m_vecPos.x, m_vecPos.y, m_vecPos.x + m_vecScale.x, m_vecPos.y + m_vecScale.y);
	ComponentRender();
}

void CL_High_Slope::Release()
{
}

void CL_High_Slope::OnCollisionEnter(CCollider* pOther)
{
}

void CL_High_Slope::OnCollisionStay(CCollider* pOther)
{
}

void CL_High_Slope::OnCollisionExit(CCollider* pOther)
{
}
