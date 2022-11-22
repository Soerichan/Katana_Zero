#include "framework.h"
#include "CScene002.h"
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
CScene002::CScene002()
{
}

CScene002::~CScene002()
{
}

void CScene002::Init()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(47, 325);
	AddGameObject(pPlayer);

	CCam* newCam01 = new CCam;
	newCam01->SetPos(1394, 1690);
	AddGameObject(newCam01);

	CSlidingDoor* newSD01 = new CSlidingDoor;
	newSD01->SetPos(1534, 1685);
	AddGameObject(newSD01);


	

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround04", L"Image\\Stage\\Stage_002_1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	m_fDeadMonsterCount002 = 6;
}

void CScene002::Enter()
{
	CDoor* newDoor01 = new CDoor;
	newDoor01->SetPos(881,761);
	AddGameObject(newDoor01);

	CDoor* newDoor02 = new CDoor;
	newDoor02->SetPos(891,1226);
	AddGameObject(newDoor02);


	CGrunt* newGrunt01 = new CGrunt;
	newGrunt01->SetPos(316,773);
	AddGameObject(newGrunt01);

	CGrunt* newGrunt02 = new CGrunt;
	newGrunt02->SetPos(677,773);
	AddGameObject(newGrunt02);

	CPomp* newPomp01 = new CPomp;
	newPomp01->SetPos(1096,1227);
	newPomp01->SetPatroller(true);
	AddGameObject(newPomp01);

	CGangster* newGangster01 = new CGangster;
	newGangster01->SetPos(1260,773);
	newGangster01->SetPatroller(true);
	//newGangster01->SetReverse(true);
	AddGameObject(newGangster01);

	CGangster* newGangster02 = new CGangster;
	newGangster02->SetPos(1310,1206);
	newGangster02->SetPatroller(true);
	AddGameObject(newGangster02);

	CGangster* newGangster03 = new CGangster;
	newGangster03->SetPos(404,1222);
	newGangster03->SetPatroller(true);
	AddGameObject(newGangster03);

	CSmokePipe* newSmokePipe01 = new CSmokePipe;
	newSmokePipe01->SetPos(1199, 1509);
	AddGameObject(newSmokePipe01);

	CSubWeapon* pSubWeapon01 = new CSubWeapon;
	pSubWeapon01->SetName(L"Butcher");
	pSubWeapon01->SetPos(738,1763);
	pSubWeapon01->SetScale(42, 42);
	CImage* newSubWeaponImage01 = new CImage;
	pSubWeapon01->SetImage(newSubWeaponImage01 = RESOURCE->LoadImg(L"Butcher", L"Image\\SubWeapon\\Butcher.png"));
	AddGameObject(pSubWeapon01);

	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile002.tile");

	CAMERA->SetTargetPos({ 47,325 });
}

void CScene002::Update()
{
	if (m_fDeadMonsterCount002 == GAME->m_iDeadMonster)
	{
		CEntrance* pEntrance001 = new CEntrance;
		pEntrance001->SetPos(1691, 1702);
		pEntrance001->SetNextScene(GroupScene::Scene003);
		AddGameObject(pEntrance001);
	}
}

void CScene002::Render()
{
}

void CScene002::Exit()
{
}

void CScene002::Release()
{
}
