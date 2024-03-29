#include "framework.h"
#include "CScene005.h"
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

#include "CElectro.h"

CScene005::CScene005()
{
}

CScene005::~CScene005()
{
}

void CScene005::Init()
{
	

	pPlayer = new CPlayer();
	pPlayer->SetPos(1250, 428);
	AddGameObject(pPlayer);


	CCameraController* pCamController = new CCameraController;

	AddGameObject(pCamController);

	m_pbackGround = new CBackGround;
	m_pbackGround->SetImage(RESOURCE->LoadImg(L"BackGround07", L"Image\\Stage\\Stage_005_1.png"));
	AddGameObject(m_pbackGround);

	//ShowCursor(false);
	m_pCursor = new CCursor;
	m_pCursor->SetImage(RESOURCE->LoadImg(L"Cursor01", L"Image\\spr_cursor_0.png"));
	AddGameObject(m_pCursor);

	m_fDeadMonsterCount005 = 1;
}

void CScene005::Enter()
{
	CHUD* pHUD = new CHUD;
	pHUD->SetPos(0, 0);
	pHUD->SetScale(1280, 46);
	AddGameObject(pHUD);

	CElectro* NEWElectro = new CElectro;
	NEWElectro->SetPos(683, 456);
	AddGameObject(NEWElectro);

	CAMERA->readyTimer = 1.f;

	CAMERA->FadeIn(1.f);


	LoadStageObject(GETPATH + L"Tile\\Tile005.tile");

	CAMERA->SetTargetPos({ 1250, 428 });

	
}

void CScene005::Update()
{
	if (m_fDeadMonsterCount005 == GAME->m_iDeadMonster && GAME->m_bClear == false)
	{
		CEntrance* pEntrance005 = new CEntrance;
		pEntrance005->SetPos(348, 435);
		pEntrance005->SetNextScene(GroupScene::Scene006);
		AddGameObject(pEntrance005);

		SOUND->Play(m_pClearSound, 0.6f);
		GAME->m_bClear = true;
	}
}

void CScene005::Render()
{
}

void CScene005::Exit()
{
}

void CScene005::Release()
{
}
