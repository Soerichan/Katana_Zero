#include "framework.h"
#include "CGround.h"

CGround::CGround()
{
}

CGround::~CGround()
{
}

void CGround::Init()
{
	CStageObject::Init();
	AddCollider(ColliderType::Rect,
		Vector(m_vecScale),
		Vector(m_vecScale.x/2,m_vecScale.y/2));

	m_strName = L"Ground";
	
}

void CGround::Update()
{
	CStageObject::Update();
}

void CGround::Render()
{
	CStageObject::Render();
	RENDER->Text(L"Ground", m_vecPos.x, m_vecPos.y, m_vecPos.x+m_vecScale.x, m_vecPos.y + m_vecScale.y);
	ComponentRender();
}

void CGround::Release()
{
}

void CGround::OnCollisionEnter(CCollider* pOther)
{
	
}

void CGround::OnCollisionStay(CCollider* pOther)
{

}

void CGround::OnCollisionExit(CCollider* pOther)
{
}
