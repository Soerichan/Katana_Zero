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
		Vector(m_vecPos),
		Vector(m_vecScale));
	
}

void CGround::Update()
{
	CStageObject::Update();
}

void CGround::Render()
{
	CStageObject::Render();

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
