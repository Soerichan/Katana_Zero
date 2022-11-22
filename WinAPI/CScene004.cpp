#include "framework.h"
#include "CScene004.h"
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
CScene004::CScene004()
{
}

CScene004::~CScene004()
{
}

void CScene004::Init()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(71, 1404);
	AddGameObject(pPlayer);

	CEntrance* pEntrance004 = new CEntrance;
	pEntrance004->SetPos(62, 396);
	pEntrance004->SetNextScene(GroupScene::Stage01);
	AddGameObject(pEntrance004);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround06", L"Image\\Stage\\Stage_004_1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);
	m_fDeadMonsterCount004 = 7;
}

void CScene004::Enter()
{
	CDoor* newDoor01 = new CDoor;
	newDoor01->SetPos(1212,930);
	AddGameObject(newDoor01);

	CDoor* newDoor02 = new CDoor;
	newDoor02->SetPos(1307,674);
	AddGameObject(newDoor02);

	CDoor* newDoor03 = new CDoor;
	newDoor03->SetPos(1522,419);
	AddGameObject(newDoor03);

	CDoor* newDoor04= new CDoor;
	newDoor04->SetPos(631,425);
	AddGameObject(newDoor04);

	CGrunt* newGrunt01 = new CGrunt;
	newGrunt01->SetPos(1055,939);
	newGrunt01->SetPatroller(true);
	AddGameObject(newGrunt01);

	CGrunt* newGrunt02 = new CGrunt;
	newGrunt02->SetPos(789,403);
	AddGameObject(newGrunt02);

	CPomp* newPomp01 = new CPomp;
	newPomp01->SetPos(2573, 224);
	newPomp01->SetPatroller(true);
	AddGameObject(newPomp01);

	CGangster* newGangster01 = new CGangster;
	newGangster01->SetPos(1401,966);
	newGangster01->SetPatroller(true);
	AddGameObject(newGangster01);

	CGangster* newGangster02 = new CGangster;
	newGangster02->SetPos(1538,963);
	//newGangster02->SetPatroller(true);
	//newGangster02->SetReverse(true);
	AddGameObject(newGangster02);

	CGangster* newGangster03 = new CGangster;
	newGangster03->SetPos(1493,693);
	newGangster03->SetPatroller(true);
	AddGameObject(newGangster03);

	CGangster* newGangster04 = new CGangster;
	newGangster04->SetPos(1024,403);
	newGangster04->SetPatroller(true);
	//newGangster01->SetReverse(true);
	AddGameObject(newGangster04);

	CSmokePipe* newSmokePipe01 = new CSmokePipe;
	newSmokePipe01->SetPos(1092,297);
	AddGameObject(newSmokePipe01);

	CLaser* pLaser01 = new CLaser;
	pLaser01->SetPos(1567,393);
	pLaser01->SetMove(true);
	AddGameObject(pLaser01);
	CLaser* pLaser02 = new CLaser;
	pLaser02->SetPos(1607, 393);
	pLaser02->SetMove(true);
	AddGameObject(pLaser02);
	CLaser* pLaser03 = new CLaser;
	pLaser03->SetPos(1647, 393);
	pLaser03->SetMove(true);
	AddGameObject(pLaser03);
	CLaser* pLaser04 = new CLaser;
	pLaser04->SetPos(1687, 393);
	pLaser04->SetMove(true);
	AddGameObject(pLaser04);


	CLaser* pLaser05 = new CLaser;
	pLaser05->SetPos(535,361);
	AddGameObject(pLaser05);
	CLaser* pLaser06 = new CLaser;
	pLaser06->SetPos(505, 361);
	AddGameObject(pLaser06);
	CLaser* pLaser07 = new CLaser;
	pLaser07->SetPos(475, 361);
	AddGameObject(pLaser07);
	CLaser* pLaser08 = new CLaser;
	pLaser08->SetPos(445, 361);
	AddGameObject(pLaser08);
	CLaser* pLaser09 = new CLaser;
	pLaser09->SetPos(415, 361);
	AddGameObject(pLaser09);
	CLaser* pLaser10 = new CLaser;
	pLaser10->SetPos(385, 361);
	AddGameObject(pLaser10);
	CLaser* pLaser11 = new CLaser;
	pLaser11->SetPos(355, 361);
	AddGameObject(pLaser11);
	CLaser* pLaser12 = new CLaser;
	pLaser12->SetPos(325, 361);
	AddGameObject(pLaser12);

	CLaserSwitch* pLaserSwitch = new CLaserSwitch;
	pLaserSwitch->SetPos(2573,224);
	AddGameObject(pLaserSwitch);

	CSubWeapon* pSubWeapon01 = new CSubWeapon;
	pSubWeapon01->SetName(L"Statue");
	pSubWeapon01->SetPos(907,965);
	pSubWeapon01->SetScale(46, 64);
	CImage* newSubWeaponImage01 = new CImage;
	pSubWeapon01->SetImage(newSubWeaponImage01 = RESOURCE->LoadImg(L"Statue", L"Image\\SubWeapon\\Statue.png"));
	AddGameObject(pSubWeapon01);


	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile004.tile");

	CAMERA->SetTargetPos({ 71, 1404 });
}

void CScene004::Update()
{

	if (m_fDeadMonsterCount004 == GAME->m_iDeadMonster)
	{
		CEntrance* pEntrance004 = new CEntrance;
		pEntrance004->SetPos(62, 396);
		pEntrance004->SetNextScene(GroupScene::Stage01);
		AddGameObject(pEntrance004);
	}
}

void CScene004::Render()
{
}

void CScene004::Exit()
{
}

void CScene004::Release()
{
}
