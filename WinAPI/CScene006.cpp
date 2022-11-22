#include "framework.h"
#include "CScene006.h"
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

CScene006::CScene006()
{
	pPlayer = nullptr;
}

CScene006::~CScene006()
{
}

void CScene006::Init()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(546, 548);
	AddGameObject(pPlayer);

	CEntrance* pEntrance005 = new CEntrance;
	pEntrance005->SetPos(85, 897);
	pEntrance005->SetNextScene(GroupScene::SceneEnding);
	AddGameObject(pEntrance005);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);


	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround02", L"Image\\Stage\\ClubEnter.png"));
	AddGameObject(m_pbackGround);
	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	m_fDeadMonsterCount006 = 4;
}

void CScene006::Enter()
{
	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile000.tile");

	CAMERA->SetTargetPos({ 546, 548 });
}

void CScene006::Update()
{
	if (m_fDeadMonsterCount006 == GAME->m_iDeadMonster)
	{
		CEntrance* pEntrance005 = new CEntrance;
		pEntrance005->SetPos(85, 897);
		pEntrance005->SetNextScene(GroupScene::SceneEnding);
		AddGameObject(pEntrance005);
	}
}

void CScene006::Render()
{
}

void CScene006::Exit()
{
}

void CScene006::Release()
{
}
