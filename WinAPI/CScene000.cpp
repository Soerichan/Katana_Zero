#include "framework.h"
#include "CScene000.h"
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

#include "CSubWeapon.h"
#include "CLaser.h"
#include "CLaserSwitch.h"
#include "CCam.h"
#include "CSlidingDoor.h"
#include "CSmokePipe.h"

#include "CCameraController.h"
#include "CButton.h"
#include "CPanel.h"

#include "CHUD.h"
#include "CBattery.h"
#include "CDoor.h"

CScene000::CScene000()
{
	pPlayer = nullptr;
}

CScene000::~CScene000()
{
}

void CScene000::Init()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(85, 897);
	AddGameObject(pPlayer);

	/*CCam* pCam = new CCam;
	pCam->SetPos(453, 356);
	AddGameObject(pCam);

	CSlidingDoor* pSD = new CSlidingDoor;
	pSD->SetPos(547, 356);
	AddGameObject(pSD);*/
	CEntrance* pEntrance000 = new CEntrance;
	pEntrance000->SetPos(546, 548);
	pEntrance000->SetNextScene(GroupScene::Scene001);
	AddGameObject(pEntrance000);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround02", L"Image\\Stage\\ClubEnter.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);
	
}

void CScene000::Enter()
{
	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile000.tile");

	CAMERA->SetTargetPos({ 85,897 });
}

void CScene000::Update()
{
}

void CScene000::Render()
{
}

void CScene000::Exit()
{
}

void CScene000::Release()
{
}
