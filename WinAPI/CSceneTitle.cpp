#include "framework.h"
#include "CSceneTitle.h"

#include "WinAPI.h"
#include "CRenderManager.h"
#include "CInputManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"

#include "CTitle_Layer01.h"

CSceneTitle::CSceneTitle()
{
}

CSceneTitle::~CSceneTitle()
{
}

void CSceneTitle::Init()
{
	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround00", L"Image\\TITLE_BG_ZERO.png"));
	AddGameObject(m_pbackGround);

	m_pLayer01 = new CTitle_Layer01;
	m_pLayer01->SetPos(577, 310);	
	AddGameObject(m_pLayer01);

	m_pLayer02 = new CTitle_Layer02;
	m_pLayer02->SetPos(805, 310);
	AddGameObject(m_pLayer02);

	m_pLayer03 = new CTitle_Layer03;
	m_pLayer03->SetPos(640, 465);
	AddGameObject(m_pLayer03);


}

void CSceneTitle::Enter()
{
	CAMERA->FadeIn(0.25f);
}

void CSceneTitle::Update()
{
	if (BUTTONDOWN(VK_F1))
	{
		CHANGESCENE(GroupScene::TileTool);
	}
	if (BUTTONDOWN(VK_SPACE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Stage01, 0.25f);
	}
}

void CSceneTitle::Render()
{
	RENDER->Text(L" Press SapceBar to Start",
		WINSIZEX * 0.5f - 150,
		WINSIZEY * 0.5f + 80,
		WINSIZEX * 0.5f + 150,
		WINSIZEY * 0.5f + 140,
		Color(255, 255, 255, 1.f),
		30.f);
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}
