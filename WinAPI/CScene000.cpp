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
#include "CBoss.h"

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
#include "CDanceFloor.h"

CScene000::CScene000()
{
	pPlayer = nullptr;
}

CScene000::~CScene000()
{
}

void CScene000::Init()
{
	

	pPlayer = new CPlayer();
	pPlayer->SetPos(85, 897);
	AddGameObject(pPlayer);


	/*CCam* pCam = new CCam;
	pCam->SetPos(453, 356);
	AddGameObject(pCam);

	CSlidingDoor* pSD = new CSlidingDoor;
	pSD->SetPos(547, 356);
	AddGameObject(pSD);*/

	CDanceFloor* pDanceFloor = new CDanceFloor;
	pDanceFloor->SetPos(696, 984);
	AddGameObject(pDanceFloor);
	CDanceFloor* pDanceFloor2 = new CDanceFloor;
	pDanceFloor2->SetPos(1904, 984);
	AddGameObject(pDanceFloor2);
	CDanceFloor* pDanceFloor3 = new CDanceFloor;
	pDanceFloor3->SetPos(891, 984);
	pDanceFloor3->SetTwo(true);
	AddGameObject(pDanceFloor3);
	CDanceFloor* pDanceFloor4 = new CDanceFloor;
	pDanceFloor4->SetPos(1392, 984);
	AddGameObject(pDanceFloor4);
	CDanceFloor* pDanceFloor5 = new CDanceFloor;
	pDanceFloor5->SetPos(1651, 984);
	pDanceFloor5->SetTwo(true);
	AddGameObject(pDanceFloor5);
	CDanceFloor* pDanceFloor6 = new CDanceFloor;
	pDanceFloor6->SetPos(764, 553);
	AddGameObject(pDanceFloor6);
	CDanceFloor* pDanceFloor7 = new CDanceFloor;
	pDanceFloor7->SetPos(2374, 553);
	AddGameObject(pDanceFloor7);
	CDanceFloor* pDanceFloor8 = new CDanceFloor;
	pDanceFloor8->SetPos(1958, 553);
	pDanceFloor8->SetTwo(true);
	AddGameObject(pDanceFloor8);
	CDanceFloor* pDanceFloor9 = new CDanceFloor;
	pDanceFloor9->SetPos(1536, 553);
	pDanceFloor9->SetTwo(true);
	AddGameObject(pDanceFloor9);
	CDanceFloor* pDanceFloor10 = new CDanceFloor;
	pDanceFloor10->SetPos(1266, 553);
	AddGameObject(pDanceFloor10);

	CDanceFloor* pDanceFloor11 = new CDanceFloor;
	pDanceFloor11->SetPos(1000, 984);
	pDanceFloor11->SetTwo(true);
	AddGameObject(pDanceFloor11);

	CEntrance* pEntrance000 = new CEntrance;
	pEntrance000->SetPos(546, 548);
	pEntrance000->SetNextScene(GroupScene::Scene001);
	AddGameObject(pEntrance000);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround02", L"Image\\Stage\\ClubEnter.png"));
	m_pbackGround->SetName(L"000");
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);
	
}

void CScene000::Enter()
{

	


	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	CGangster* newGangster01 = new CGangster;
	newGangster01->SetPos(1350,944);
	newGangster01->SetReverse(true);
	AddGameObject(newGangster01);

	CGangster* newGangster02 = new CGangster;
	newGangster02->SetPos(1750, 944);
	AddGameObject(newGangster02);

	CGangster* newGangster03 = new CGangster;
	newGangster03->SetPos(1950, 524);
	AddGameObject(newGangster03);

	//CGangster* newGangster04 = new CGangster;
	//newGangster04->SetPos(1450, 524);
	
	//AddGameObject(newGangster04);

	CGangster* newGangster05 = new CGangster;
	newGangster05->SetPos(1050, 524);
	newGangster05->SetReverse(true);
	AddGameObject(newGangster05);

	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile000.tile");

	CAMERA->SetTargetPos({ 85,897 });

	SOUND->Resume2(GAME->m_pBGM_Main_Sound,0.4f);
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
