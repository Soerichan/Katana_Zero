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
	CScene* pCurScene = SCENE->GetCurScene();//����� �ľ�
	const list<CGameObject*>& SubWeaponObject = pCurScene->m_listObj[(int)Layer::SubWeapon];//��������ִ� ��������� ����Ʈ ����

	/*auto iter = min_element(SubWeaponObject.begin(), SubWeaponObject.end(), [&](CGameObject* left, CGameObject* right)
		{
			if()
		});*/

	//map<float, CGameObject> mapSubWeapon;									//�Ÿ��� ������ ¦���� ��
	priority_queue<pair<float, CGameObject*>, vector<pair<float, CGameObject*>>, greater<>> queueSubWeapon;	//���� ���� �켱���� ť


	for (CGameObject* pSubWeapon : SubWeaponObject) //�����ִ� ��� ������� ��������� ���Ͽ�
	{
		Vector vecDistance = pSubWeapon->GetPos() - PLAYERPOSITION; 
		float fDistance = vecDistance.Length();
		
		queueSubWeapon.push(make_pair(fDistance, pSubWeapon));

		 //�ʿ� �������� �켱����ť�� ����
		
	}
	if (queueSubWeapon.empty() != true)
	{

		if (queueSubWeapon.top().first < 100.f)
		{
			SubWeaponName = queueSubWeapon.top().second->GetName(); //�÷��̾�� �� ��������� ������ ����

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
