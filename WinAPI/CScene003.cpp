#include "framework.h"
#include "CScene003.h"

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

CScene003::CScene003()
{
}

CScene003::~CScene003()
{
}

void CScene003::Init()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(30, 790);
	AddGameObject(pPlayer);

	CEntrance* pEntrance001 = new CEntrance;
	pEntrance001->SetPos(3244, 430);
	pEntrance001->SetNextScene(GroupScene::Scene004);
	AddGameObject(pEntrance001);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround05", L"Image\\Stage\\Stage_003_1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);
}

void CScene003::Enter()
{
	CDoor* newDoor01 = new CDoor;
	newDoor01->SetPos(1478,435);
	AddGameObject(newDoor01);

	CDoor* newDoor02 = new CDoor;
	newDoor02->SetPos(2271,435);
	AddGameObject(newDoor02);

	CPomp* newPomp01 = new CPomp;
	newPomp01->SetPos(870,461);
	AddGameObject(newPomp01);

	CPomp* newPomp02 = new CPomp;
	newPomp02->SetPos(341,461);
	newPomp02->SetPatroller(true);
	AddGameObject(newPomp02);

	CGangster* newGangster01 = new CGangster;
	newGangster01->SetPos(1565,441);
	newGangster01->SetPatroller(true);
	AddGameObject(newGangster01);

	CGangster* newGangster02 = new CGangster;
	newGangster02->SetPos(1991,441);
	//newGangster02->SetPatroller(true);
	newGangster02->SetReverse(true);
	AddGameObject(newGangster02);

	CGangster* newGangster03 = new CGangster;
	newGangster03->SetPos(2001,441);
	newGangster03->SetPatroller(true);
	AddGameObject(newGangster03);

	CGangster* newGangster04 = new CGangster;
	newGangster04->SetPos(2015,441);
	newGangster04->SetPatroller(true);
	//newGangster01->SetReverse(true);
	AddGameObject(newGangster04);

	CGangster* newGangster05 = new CGangster;
	newGangster05->SetPos(2697,441);
	//newGangster05->SetPatroller(true);
	AddGameObject(newGangster05);

	CSmokePipe* newSmokePipe01 = new CSmokePipe;
	newSmokePipe01->SetPos(1757,249);
	AddGameObject(newSmokePipe01);

	CSubWeapon* pSubWeapon01 = new CSubWeapon;
	pSubWeapon01->SetName(L"Pot");
	pSubWeapon01->SetPos(1155,450);
	pSubWeapon01->SetScale(32, 46);
	CImage* newSubWeaponImage01 = new CImage;
	pSubWeapon01->SetImage(newSubWeaponImage01 = RESOURCE->LoadImg(L"Pot", L"Image\\SubWeapon\\Pot.png"));
	AddGameObject(pSubWeapon01);



	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile003.tile");

	CAMERA->SetTargetPos({ 30, 790 });
}

void CScene003::Update()
{
}

void CScene003::Render()
{
}

void CScene003::Exit()
{
}

void CScene003::Release()
{
}
