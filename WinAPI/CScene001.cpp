#include "framework.h"
#include "CScene001.h"
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

CScene001::CScene001()
{
	pPlayer = nullptr;
}

CScene001::~CScene001()
{
}

void CScene001::Init()
{
	

	pPlayer = new CPlayer();
	pPlayer->SetPos(38, 512);
	AddGameObject(pPlayer);

	CCam* newCam01 = new CCam;
	newCam01->SetPos(503, 478);
	AddGameObject(newCam01);

	CCam* newCam02 = new CCam;
	newCam02->SetPos(1751, 478);
	AddGameObject(newCam02);

	CSlidingDoor* newSD01 = new CSlidingDoor;
	newSD01->SetPos(768, 471);
	AddGameObject(newSD01);

	CSlidingDoor* newSD02 = new CSlidingDoor;
	newSD02->SetPos(1960, 471);
	AddGameObject(newSD02);




	

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround03", L"Image\\Stage\\Stage_001_1.png"));
	AddGameObject(m_pbackGround);

	ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	m_fDeadMonsterCount001 = 5;
}

void CScene001::Enter()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	CDoor* newDoor01 = new CDoor;
	newDoor01->SetPos(1115, 487);
	AddGameObject(newDoor01);

	CGrunt* newGrunt01 = new CGrunt;
	newGrunt01->SetPos(647, 512);
	AddGameObject(newGrunt01);

	CGrunt* newGrunt02 = new CGrunt;
	newGrunt02->SetPos(1386, 512);
	AddGameObject(newGrunt02);

	CGrunt* newGrunt03 = new CGrunt;
	newGrunt03->SetPos(1848, 512);
	newGrunt03->SetPatroller(true);
	AddGameObject(newGrunt03);

	CPomp* newPomp01 = new CPomp;
	newPomp01->SetPos(1592, 512);
	newPomp01->SetPatroller(true);
	AddGameObject(newPomp01);

	CSubWeapon* pSubWeapon01 = new CSubWeapon;
	pSubWeapon01->SetName(L"Butcher");
	pSubWeapon01->SetPos(959, 508);
	pSubWeapon01->SetScale(42, 42);
	CImage* newSubWeaponImage01 = new CImage;
	pSubWeapon01->SetImage(newSubWeaponImage01 = RESOURCE->LoadImg(L"Butcher", L"Image\\SubWeapon\\Butcher.png"));
	AddGameObject(pSubWeapon01);

	CSubWeapon* pSubWeapon02 = new CSubWeapon;
	pSubWeapon02->SetName(L"Smoker");
	pSubWeapon02->SetPos(1619, 508);
	pSubWeapon02->SetScale(28, 42);
	CImage* newSubWeaponImage02 = new CImage;
	pSubWeapon02->SetImage(newSubWeaponImage02 = RESOURCE->LoadImg(L"Smoker", L"Image\\SubWeapon\\Smoker.png"));
	AddGameObject(pSubWeapon02);



	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile001.tile");

	CAMERA->SetTargetPos({ 38,512 });

	m_bOnce = false;
}

void CScene001::Update()
{
	if (PLAYERPOSITION.x > 700 && m_bOnce == false)
	{
		CPomp* newPomp02 = new CPomp;
		newPomp02->SetPos(62, 512);
		newPomp02->SetState(MonsterState::Chase);
		AddGameObject(newPomp02);

		m_bOnce = true;
	}

	if (m_fDeadMonsterCount001 == GAME->m_iDeadMonster&& GAME->m_bClear == false)
	{
		CEntrance* pEntrance001 = new CEntrance;
		pEntrance001->SetPos(2242, 458);
		pEntrance001->SetNextScene(GroupScene::Scene002);
		AddGameObject(pEntrance001);
		SOUND->Play(m_pClearSound, 0.6f);
		GAME->m_bClear = true;
	}
}

void CScene001::Render()
{
}

void CScene001::Exit()
{
}

void CScene001::Release()
{
}
