#include "framework.h"
#include "CSceneEnding.h"

CSceneEnding::CSceneEnding()
{
}

CSceneEnding::~CSceneEnding()
{
}

void CSceneEnding::Init()
{
	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround08", L"Image\\Stage\\End.png"));
	AddGameObject(m_pbackGround);
}

void CSceneEnding::Enter()
{
	CAMERA->FadeIn(1.f);
}

void CSceneEnding::Update()
{
}

void CSceneEnding::Render()
{
}

void CSceneEnding::Exit()
{
}

void CSceneEnding::Release()
{
}
