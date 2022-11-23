#include "framework.h"
#include "CWall.h"

CWall::CWall()
{
}

CWall::~CWall()
{
}

void CWall::Init()
{
	CStageObject::Init();
	AddCollider(ColliderType::Rect,
		Vector(m_vecScale),
		Vector(m_vecScale.x / 2, m_vecScale.y / 2));

	m_strName = L"Wall";
}

void CWall::Update()
{
}

void CWall::Render()
{
	if (GAME->Godmod)
	{
		CStageObject::Render();
		RENDER->Text(L"Wall", m_vecPos.x, m_vecPos.y, m_vecPos.x + m_vecScale.x, m_vecPos.y + m_vecScale.y);
		ComponentRender();
	}
}

void CWall::Release()
{
}

void CWall::OnCollisionEnter(CCollider* pOther)
{
}

void CWall::OnCollisionStay(CCollider* pOther)
{
}

void CWall::OnCollisionExit(CCollider* pOther)
{
}
