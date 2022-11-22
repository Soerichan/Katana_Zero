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

CSceneStage01::CSceneStage01()
{
	pPlayer = nullptr;
}

CSceneStage01::~CSceneStage01()
{
}

void CSceneStage01::Init()
{
	


	/*CBattery* pBattery = new CBattery;
	pBattery->SetPos(0, 0);
	pBattery->SetScale(154, 38);
	AddGameObject(pBattery);*/
	

	pPlayer = new CPlayer();
	pPlayer->SetPos(2000, 1000);
	AddGameObject(pPlayer);

	


	//CSmokePipe* pSmokePipe = new CSmokePipe;
	//pSmokePipe->SetPos(527, 314);
	//AddGameObject(pSmokePipe);

	//CCam* pCam = new CCam;
	//pCam->SetPos(453, 356);
	//AddGameObject(pCam);

	//CSlidingDoor* pSD = new CSlidingDoor;
	//pSD->SetPos(547, 356);
	//AddGameObject(pSD);

	CCameraController* pCamController = new CCameraController;
	
	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround01", L"Image\\Stage\\KATANA_MAP_club_last1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	//CImage* pImg= new CImage;
	//pImg->Load(GETPATH + L"Image\\KATANA_MAP_club.png");
	//AddGameObject(pImg);
	//m_BGImage = RESOURCE->LoadImg(L"BG", L"Image\\KATANA_MAP_club.png");


	m_fDeadMonsterCount007 = 13;
}

void CSceneStage01::Enter()
{	

	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	CGrunt* pGrunt = new CGrunt();
	pGrunt->SetPos(928,992);
	/*pGrunt->SetStair(Vector(1922, 500));*/
	AddGameObject(pGrunt);

	CPomp* pPomp = new CPomp();
	pPomp->SetPos(800,431);
	/*pPomp->SetStair(Vector(439, 782));*/
	AddGameObject(pPomp);

	CPomp* newPomp01 = new CPomp;
	newPomp01->SetPos(850,716);
	newPomp01->SetPatroller(true);
	AddGameObject(newPomp01);

	CPomp* newPomp02 = new CPomp;
	newPomp02->SetPos(875,716);
	newPomp02->SetPatroller(true);
	AddGameObject(newPomp02);

	CPomp* newPomp03 = new CPomp;
	newPomp03->SetPos(900,716);
	newPomp03->SetPatroller(true);
	AddGameObject(newPomp03);

	CPomp* newPomp04 = new CPomp;
	newPomp04->SetPos(916,716);
	newPomp04->SetPatroller(true);
	AddGameObject(newPomp04);

	CPomp* newPomp05 = new CPomp;
	newPomp05->SetPos(1522,990);
	newPomp05->SetPatroller(true);
	AddGameObject(newPomp05);

	CGangster* pGangster01 = new CGangster;
	pGangster01->SetPos(1519,431);
	AddGameObject(pGangster01);

	CGangster* pGangster02 = new CGangster;
	pGangster02->SetPos(1579,431);
	AddGameObject(pGangster02);

	CGangster* pGangster03 = new CGangster;
	pGangster03->SetPos(315,431);
	pGangster03->SetPatroller(true);
	AddGameObject(pGangster03);

	CGangster* pGangster04 = new CGangster;
	pGangster04->SetPos(1656,431);
	pGangster04->SetPatroller(true);
	AddGameObject(pGangster04);

	CGangster* pGangster05 = new CGangster;
	pGangster05->SetPos(854,431);
	AddGameObject(pGangster05);

	CGangster* pGangster06 = new CGangster;
	pGangster06->SetPos(900,431);
	pGangster06->SetPatroller(true);
	AddGameObject(pGangster06);

	CSubWeapon* pSubWeapon = new CSubWeapon;
	pSubWeapon->SetName(L"Bottle03");
	pSubWeapon->SetPos(280, 730);
	pSubWeapon->SetScale(24, 48);
	CImage* newSubWeaponImage = new CImage;
	pSubWeapon->SetImage(newSubWeaponImage = RESOURCE->LoadImg(L"Bottle01", L"Image\\SubWeapon\\Bottle03.png"));
	AddGameObject(pSubWeapon);

	CSubWeapon* pSubWeapon2 = new CSubWeapon;
	pSubWeapon2->SetName(L"Butcher");
	pSubWeapon2->SetPos(180, 723);
	pSubWeapon2->SetScale(42, 42);
	CImage* newSubWeaponImage2 = new CImage;
	pSubWeapon2->SetImage(newSubWeaponImage2 = RESOURCE->LoadImg(L"Butcher", L"Image\\SubWeapon\\Butcher.png"));
	AddGameObject(pSubWeapon2);

	CSubWeapon* pSubWeapon3 = new CSubWeapon;
	pSubWeapon3->SetName(L"Bottle02");
	pSubWeapon3->SetPos(150, 780);
	pSubWeapon3->SetScale(24, 48);
	pSubWeapon3->SetAngle(90.f);
	CImage* newSubWeaponImage3 = new CImage;
	pSubWeapon3->SetImage(newSubWeaponImage3 = RESOURCE->LoadImg(L"Bottle02", L"Image\\SubWeapon\\Bottle02.png"));
	AddGameObject(pSubWeapon3);

	CSubWeapon* pSubWeapon4 = new CSubWeapon;
	pSubWeapon4->SetName(L"Knife");
	pSubWeapon4->SetPos(130, 770);
	pSubWeapon4->SetScale(50, 16);
	pSubWeapon4->SetAngle(120.f);
	CImage* newSubWeaponImage4 = new CImage;
	pSubWeapon4->SetImage(newSubWeaponImage4 = RESOURCE->LoadImg(L"Knife", L"Image\\SubWeapon\\Knife.png"));
	AddGameObject(pSubWeapon4);

	CDoor* pDoor1 = new CDoor;
	pDoor1->SetPos(1765, 998);
	AddGameObject(pDoor1);

	CDoor* pDoor2 = new CDoor;
	pDoor2->SetPos(1267, 998);
	AddGameObject(pDoor2);

	CDoor* pDoor03 = new CDoor;
	pDoor03->SetPos(540,428);
	AddGameObject(pDoor03);


	CDoor* pDoor04 = new CDoor;
	pDoor04->SetPos(1369,428);
	AddGameObject(pDoor04);

	CLaser* pLaser1 = new CLaser;
	pLaser1->SetPos(1455, 407);
	AddGameObject(pLaser1);

	CLaser* pLaser2 = new CLaser;
	pLaser2->SetPos(1505, 407);
	AddGameObject(pLaser2);

	CLaser* pLaser3 = new CLaser;
	pLaser3->SetPos(1555, 407);
	AddGameObject(pLaser3);

	CLaser* pLaser4 = new CLaser;
	pLaser4->SetPos(1605, 407);
	AddGameObject(pLaser4);

	CLaser* pLaser5 = new CLaser;
	pLaser5->SetPos(1655, 407);
	AddGameObject(pLaser5);

	CLaser* pLaser6 = new CLaser;
	pLaser6->SetPos(1705, 407);
	AddGameObject(pLaser6);

	CLaser* pLaser7 = new CLaser;
	pLaser7->SetPos(1755, 407);
	AddGameObject(pLaser7);

	CLaser* pLaser8 = new CLaser;
	pLaser8->SetPos(1805, 407);
	AddGameObject(pLaser8);

	CLaserSwitch* pLaserSwitch = new CLaserSwitch;
	pLaserSwitch->SetPos(1477, 694);
	AddGameObject(pLaserSwitch);

	

	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\club01.tile");

	CAMERA->SetTargetPos({ 1560,790 });

	GAME->LaserOff = true;
}

void CSceneStage01::Update()
{
	if (m_fDeadMonsterCount007 == GAME->m_iDeadMonster && GAME->m_bClear == false)
	{
		CEntrance* pEntrans = new CEntrance;
		pEntrans->SetPos(17, 405);
		pEntrans->SetNextScene(GroupScene::Scene005);
		AddGameObject(pEntrans);
		SOUND->Play(m_pClearSound, 0.6f);
		GAME->m_bClear = true;
	}
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
