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
#include "CGrunt.h"
#include "CPomp.h"
#include "CGangster.h"


#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"

#include "CHUD.h"

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

	CGrunt* pGrunt = new CGrunt();
	pGrunt->SetPos(1000, WINSIZEY * 0.5f);
	/*pGrunt->SetStair(Vector(1922, 500));*/
	AddGameObject(pGrunt);

	CPomp* pPomp = new CPomp();
	pPomp->SetPos(1000, WINSIZEY * 0.8f);
	/*pPomp->SetStair(Vector(439, 782));*/
	AddGameObject(pPomp);

	CGangster* pGangster = new CGangster;
	pGangster->SetPos(1000, WINSIZEY * 1.f);
	AddGameObject(pGangster);
	


	CCameraController* pCamController = new CCameraController;
	
	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround01", L"Image\\KATANA_MAP_club_last1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	//CImage* pImg= new CImage;
	//pImg->Load(GETPATH + L"Image\\KATANA_MAP_club.png");
	//AddGameObject(pImg);
	//m_BGImage = RESOURCE->LoadImg(L"BG", L"Image\\KATANA_MAP_club.png");



}

void CSceneStage01::Enter()
{	
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0,0);
	pHUD->SetScale(1280,46);
	ADDOBJECT(pHUD);

	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\club01.tile");

	CAMERA->SetTargetPos({ 1560,790 });
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
