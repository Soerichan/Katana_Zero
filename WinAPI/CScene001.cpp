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
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	pPlayer = new CPlayer();
	pPlayer->SetPos(38, 512);
	AddGameObject(pPlayer);

	CEntrance* pEntrance001 = new CEntrance;
	pEntrance001->SetPos(2242, 458);
	pEntrance001->SetNextScene(GroupScene::Scene002);
	AddGameObject(pEntrance001);

	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround03", L"Image\\Stage\\Stage_001_1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);
}

void CScene001::Enter()
{
	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile001.tile");

	CAMERA->SetTargetPos({ 38,512 });
}

void CScene001::Update()
{
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
