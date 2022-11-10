#include "framework.h"
#include "CSceneStage01.h"

#include "WinAPI.h"
#include "CInputManager.h"
#include "CTimeManager.h"
#include "CRenderManager.h"
#include "CEventManager.h"
#include "CCameraManager.h"
#include "CPathManager.h"

#include "CPlayer.h"
#include "CMonster.h"
#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	pPlayer = new CPlayer();
	pPlayer->SetPos(2000, 1000);
	AddGameObject(pPlayer);

	CMonster* pMonster = new CMonster();
	pMonster->SetPos(1000, WINSIZEY * 0.5f);
	AddGameObject(pMonster);

	CCameraController* pCamController = new CCameraController;
	
	AddGameObject(pCamController);

	//CImage* pImg= new CImage;
	//pImg->Load(GETPATH + L"Image\\KATANA_MAP_club.png");
	//AddGameObject(pImg);
	//m_BGImage = RESOURCE->LoadImg(L"BG", L"Image\\KATANA_MAP_club.png");



}

void CSceneStage01::Enter()
{
	CAMERA->FadeIn(0.25f);
	LoadStageObject(GETPATH + L"Tile\\club01.tile");

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround01", L"Image\\KATANA_MAP_club_last1.png"));
	AddGameObject(m_pbackGround);
}

void CSceneStage01::Update()
{
	//CAMERA->SetTargetObj(pPlayer);
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CAMERA->FadeOut(0.25f);
		DELAYCHANGESCENE(GroupScene::Title, 0.25f);
	}
}

void CSceneStage01::Render()
{
}

void CSceneStage01::Exit()
{
}

void CSceneStage01::Release()
{
}
