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
		(vecToolMousePos),
		(vecToolMousePos2));
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
