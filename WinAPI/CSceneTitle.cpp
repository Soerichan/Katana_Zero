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

	m_pLayer04 = new CTitle_Layer04;
	m_pLayer04->SetPos(630, 245);
	
	AddGameObject(m_pLayer04);

	m_pTitleSound = RESOURCE->LoadSound(L"StartButton", L"Sound\\StartButton.wav");

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
	if (BUTTONDOWN(VK_F2))
	{
		CHANGESCENE(GroupScene::Scene005);
		SOUND->Stop(GAME->m_pBGM_Start_Sound);
	}
	if (BUTTONDOWN(VK_SPACE))
	{	
		//SOUND->Play(m_pTitleSound,0.5f);
		SOUND->Stop(GAME->m_pBGM_Start_Sound);
		SOUND->Pause(GAME->m_pBGM_Main_Sound);
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Scene_file, 0.25f);
	}
}

void CSceneTitle::Render()
{
	

	RENDER->Text(L" Press  SpaceBar  to  Start",
		WINSIZEX * 0.5f - 167,
		WINSIZEY * 0.5f + 100,
		WINSIZEX * 0.5f + 163,
		WINSIZEY * 0.5f + 180,
		Color(255, 0, 255, 1.f),
		30.f);

	RENDER->Text(L" Press  SpaceBar  to  Start",
		WINSIZEX * 0.5f - 163,
		WINSIZEY * 0.5f + 100,
		WINSIZEX * 0.5f + 167,
		WINSIZEY * 0.5f + 180,
		Color(0, 255, 255, 1.f),
		30.f);

	RENDER->Text(L" Press  SpaceBar  to  Start",
		WINSIZEX * 0.5f - 165,
		WINSIZEY * 0.5f + 100,
		WINSIZEX * 0.5f + 165,
		WINSIZEY * 0.5f + 180,
		Color(255, 255, 255, 1.f),
		30.f);
}

void CSceneTitle::Exit()
{
}

void CSceneTitle::Release()
{
}
