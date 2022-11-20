#include "framework.h"
#include "CEntrance.h"

CEntrance::CEntrance()
{
	m_layer = Layer::StageObject;
	m_strName = L"Entrance";
	m_vecPos = {};

	
}

CEntrance::~CEntrance()
{
}

GroupScene CEntrance::GetNextScene()
{
	return pNextScene;
}

void CEntrance::SetNextScene(GroupScene Scene)
{
	pNextScene = Scene;
}

void CEntrance::Init()
{
	AddCollider(ColliderType::Rect, Vector(100, 200), Vector(0, 0));
}

void CEntrance::Update()
{

}

void CEntrance::Render()
{

}

void CEntrance::Release()
{

}

void CEntrance::OnCollisionEnter(CCollider* pOtherCollider)
{
	DELAYCHANGESCENE(pNextScene,0.25f);
}
