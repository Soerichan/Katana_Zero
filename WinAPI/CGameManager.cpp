#include "framework.h"
#include "CGameManager.h"
#include "CSceneManager.h"
#include "CGameObject.h"
#include "CScene.h"


CGameManager::CGameManager()
{
	PlayerPos = {};
	Battery = 0;
	SubWeaponName = L"None";
	LaserOff = false;
	Remodeling = false;
	m_iDeadMonster = 0;
	
	
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
	 m_pBGM_Main_Sound= RESOURCE->LoadSound(L"BGM_Main", L"Sound\\BGM.mp3");
	 m_pBGM_Start_Sound= RESOURCE->LoadSound(L"BGM_Start", L"Sound\\Start.mp3");
	 m_pBGM_BOSS_Sound= RESOURCE->LoadSound(L"BGM_Boss", L"Sound\\Boss.mp3");

	SOUND->Play(GAME->m_pBGM_Main_Sound,0.f);
	
	SOUND->Play(m_pBGM_Start_Sound);
}

void CGameManager::Update()
{
	if (Remodeling)
	{
		CScene* nowScene = SCENE->GetCurScene();

		//nowScene->SceneExit();
		nowScene->DeleteLayerObject(Layer::Laser);
		nowScene->DeleteLayerObject(Layer::Monster);
		nowScene->DeleteLayerObject(Layer::SubWeapon);
		nowScene->DeleteLayerObject(Layer::Door);
		nowScene->DeleteLayerObject(Layer::EnemyMissile);
		nowScene->DeleteLayerObject(Layer::Corpse);
		nowScene->DeleteLayerObject(Layer::Smoke);
		nowScene->DeleteLayerObject(Layer::Effect);

		nowScene->SceneEnter();
		Remodeling = false;
	}
	

}

void CGameManager::Release()
{
}

void CGameManager::PlayerSubWeapon()
{
	
}

void CGameManager::PickUpProcess()
{
	CScene* pCurScene = SCENE->GetCurScene();//현재씬 파악
	const list<CGameObject*>& SubWeaponObject = pCurScene->m_listObj[(int)Layer::SubWeapon];//현재씬에있는 서브웨폰을 리스트 만듬

	/*auto iter = min_element(SubWeaponObject.begin(), SubWeaponObject.end(), [&](CGameObject* left, CGameObject* right)
		{
			if()
		});*/

	//map<float, CGameObject> mapSubWeapon;									//거리와 원본을 짝지을 맵
	priority_queue<pair<float, CGameObject*>, vector<pair<float, CGameObject*>>, greater<>> queueSubWeapon;	//맵을 넣을 우선순위 큐


	for (CGameObject* pSubWeapon : SubWeaponObject) //남아있는 모든 현재씬의 서브웨폰에 대하여
	{
		Vector vecDistance = pSubWeapon->GetPos() - PLAYERPOSITION; 
		float fDistance = vecDistance.Length();
		
		queueSubWeapon.push(make_pair(fDistance, pSubWeapon));

		 //맵에 넣은것을 우선순위큐에 넣음
		
	}
	if (queueSubWeapon.empty() != true)
	{

		if (queueSubWeapon.top().first < 100.f)
		{
			SubWeaponName = queueSubWeapon.top().second->GetName(); //플레이어에게 줄 서브웨폰의 정보를 저장

			DELETEOBJECT(queueSubWeapon.top().second);
		}
	}
	else
	{
		SubWeaponName = L"None";
	}

}

void CGameManager::SubWeaponThrow()
{
	SubWeaponName = L"None";
	PickUpProcess();
}

//void CGameManager::SaveMemento(Vector  Playerpos)
//{
//	Memento* newMemento = new Memento;
//	newMemento->SetPlayerVector(Playerpos);
//	externCareTaker.Addplayer(newMemento);
//}
//
//Memento* CGameManager::GetMemento()
//{
//	return externCareTaker.Popplayer();
//}
