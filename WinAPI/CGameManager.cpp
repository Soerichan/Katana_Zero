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
}

CGameManager::~CGameManager()
{
}

void CGameManager::Init()
{
}

void CGameManager::Update()
{
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
