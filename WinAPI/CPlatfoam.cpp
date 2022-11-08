#include "framework.h"
#include "CPlatfoam.h"

CPlatfoam::CPlatfoam()
{
}

CPlatfoam::~CPlatfoam()
{
}

void CPlatfoam::Init()
{
	CStageObject::Init();
	AddCollider(ColliderType::Rect,
		Vector(m_vecScale),
		Vector(m_vecScale.x / 2, m_vecScale.y / 2));

	m_strName = L"Platfoam";
}

void CPlatfoam::Update()
{
}

void CPlatfoam::Render()
{
	CStageObject::Render();
	RENDER->Text(L"Platfoam", m_vecPos.x, m_vecPos.y, m_vecPos.x + m_vecScale.x, m_vecPos.y + m_vecScale.y);
	ComponentRender();
}

void CPlatfoam::Release()
{
}

void CPlatfoam::OnCollisionEnter(CCollider* pOther)
{
}

void CPlatfoam::OnCollisionStay(CCollider* pOther)
{
}

void CPlatfoam::OnCollisionExit(CCollider* pOther)
{
}
