#include "framework.h"
#include "CScene.h"

#include "CCameraManager.h"
#include "CGameObject.h"
#include "CTile.h"
#include "CGroundTile.h"
#include"CDoor.h"
#include "CScene000.h"
#include "CScene001.h"
#include "CScene002.h"
#include "CScene003.h"
#include "CScene004.h"
#include "CScene005.h"
#include "CScene006.h"

CScene::CScene()
{
	m_iTileSizeX = 0;
	m_iTileSizeY = 0;
}

CScene::~CScene()
{
}

void CScene::SceneInit()
{
	// �� ���� ��� ���ӿ�����Ʈ �ʱ�ȭ
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectInit();
		}
	}

	// ����� �ڽ� �ʱ�ȭ
	Init();
}

void CScene::SceneEnter()
{
	// ���� ���� ī�޶� ��Ȳ�� �ʱ�ȭ�ϰ� ī�޶��� ��ġ�� �ʱ� ��ġ��
	// ���� ī�޶� ������ġ�� �ʱ� ��ġ�� �ƴѰ�� ���� Enter���� ��ġ�� �����Ͽ� ��ǥ��ġ�� ���
	CAMERA->SetTargetObj(nullptr);
	CAMERA->SetTargetPos(Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));
	externCareTaker.PopClear();
	GAME->LaserOff = false;
	Enter();
}

void CScene::SceneUpdate()
{
	// �� ���� �����ص� ������ ���ӿ�����Ʈ�� ����
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		m_listObj[layer].remove_if([](CGameObject* target)
			{
				if (target->GetSafeToDelete())
				{
					target->GameObjectRelease();
					delete target;
					return true;
				}
				else
					return false;
			});
	}

	// �� ���� ��� ���ӿ�����Ʈ ��������
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			if (pGameObject->GetReserveDelete())
				pGameObject->SetSafeToDelete();
			else
				pGameObject->GameObjectUpdate();
		}
	}

	// ����� �ڽ� ��������
	Update();
}

void CScene::ScenePhysicsUpdate()
{
	// �� ���� ��� ���ӿ�����Ʈ ����ó�� ����
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectPhysicsUpdate();
		}
	}
}

void CScene::SceneRender()
{
	// �� ���� ��� ���ӿ�����Ʈ ǥ������
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		if ((int)Layer::StageObject == layer)
		{
			StageObjectRender();
			continue;
		}
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectRender();
		}
	}

	// ����� �ڽ� ǥ������
	Render();
}

void CScene::SceneExit()
{
	Exit();
}

void CScene::SceneRelease()
{
	// �� ���� ��� ���ӿ�����Ʈ ������
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectRelease();
			delete pGameObject;
		}
		m_listObj[layer].clear();
	}

	// ����� �ڽ� ������
	Release();
}

void CScene::StageObjectRender()
{
	// ���� ȭ�鿡 ǥ�õ��� �ʴ� Ÿ���� �������� �������� ����
	//Vector vecCamLook = CAMERA->GetLookAt();
	//Vector vecLeftTop = vecCamLook - Vector(WINSIZEX, WINSIZEY) / 2.f;

	//int iLTX = (int)vecLeftTop.x / CTile::TILESIZE;
	//int iLTY = (int)vecLeftTop.y / CTile::TILESIZE;
	//int iRBX = (int)WINSIZEX / CTile::TILESIZE;
	//int iRBY = (int)WINSIZEY / CTile::TILESIZE;

	for (CGameObject* pGameObject : m_listObj[(int)Layer::StageObject])
{
		CStageObject* pStageObject = (CStageObject*)pGameObject;
	
			pStageObject->Render();
	}
}

void CScene::LoadStageObject(const wstring& strPath)
{
	DeleteLayerObject(Layer::StageObject);

	FILE* pFile = nullptr;

	_wfopen_s(&pFile, strPath.c_str(), L"rb");      // w : write, b : binary
	assert(pFile);

	//UINT xCount = 0;
	//UINT yCount = 0;
	//UINT tileCount = 0;

	//fread(&xCount, sizeof(UINT), 1, pFile);
	//fread(&yCount, sizeof(UINT), 1, pFile);
	//fread(&tileCount, sizeof(UINT), 1, pFile);

	//CTile loadTile;
	//for (UINT i = 0; i < tileCount; i++)
	//{
	//	loadTile.Load(pFile);

	//	// TODO : Ÿ�� Ÿ�Կ� ���� ����
	//	if (TypeTile::None == loadTile.GetType())
	//	{
	//		CTile* newTile = new CTile;
	//		newTile->SetTilePos(loadTile.GetTilePosX(), loadTile.GetTilePosY());
	//		newTile->SetTileIndex(loadTile.GetTileIndex());

	//		AddGameObject(newTile);
	//	}
	//	else if (TypeTile::Ground == loadTile.GetType())
	//	{
	//		CGroundTile* newTile = new CGroundTile;
	//		newTile->SetTilePos(loadTile.GetTilePosX(), loadTile.GetTilePosY());
	//		newTile->SetTileIndex(loadTile.GetTileIndex());

	//		AddGameObject(newTile);
	//	}
	//}

	//fclose(pFile);

	UINT objCount = 0;
	fread(&objCount, sizeof(UINT), 1, pFile);
	CStageObject loadStageObject;
	for (UINT count = 0; count < objCount; count++)
	{
		loadStageObject.Load(pFile);

		switch (loadStageObject.GetType())
		{
		case TypeStageObject::Ground:
		{
			CGround* newStageObject = new CGround;
			newStageObject->SetPos(loadStageObject.GetPos());
			newStageObject->SetScale(loadStageObject.GetScale());
			newStageObject->SetType(loadStageObject.GetType());
			ADDOBJECT(newStageObject);
			break;
		}

		case  TypeStageObject::Wall:
		{
			CWall* newStageObject = new CWall;
			newStageObject->SetPos(loadStageObject.GetPos());
			newStageObject->SetScale(loadStageObject.GetScale());
			newStageObject->SetType(loadStageObject.GetType());
			ADDOBJECT(newStageObject);
			break;
		}

		case  TypeStageObject::R_Hihg_Slope:
		{
			CR_High_Slope* newStageObject = new CR_High_Slope;
			newStageObject->SetPos(loadStageObject.GetPos());
			newStageObject->SetScale(loadStageObject.GetScale());
			newStageObject->SetType(loadStageObject.GetType());
			ADDOBJECT(newStageObject);
			break;
		}

		case TypeStageObject::L_Hihg_Slope:
		{
			CL_High_Slope* newStageObject = new CL_High_Slope;
			newStageObject->SetPos(loadStageObject.GetPos());
			newStageObject->SetScale(loadStageObject.GetScale());
			newStageObject->SetType(loadStageObject.GetType());
			ADDOBJECT(newStageObject);
			break;
		}

		case TypeStageObject::Platfoam:
		{
			CPlatfoam* newStageObject = new CPlatfoam;
			newStageObject->SetPos(loadStageObject.GetPos());
			newStageObject->SetScale(loadStageObject.GetScale());
			newStageObject->SetType(loadStageObject.GetType());
			ADDOBJECT(newStageObject);
			break;
		}
		/*

		CStageObject* pStageObject = new CStageObject;
		pStageObject->SetPos(loadStageObject.GetPos());
		pStageObject->SetScale(loadStageObject.GetScale());
		pStageObject->SetType(loadStageObject.GetType());
		ADDOBJECT(pStageObject);
		*/
		}
	/*	CStageObject* pStageObject = new CStageObject;
		pStageObject->SetPos(loadStageObject.GetPos());
		pStageObject->SetScale(loadStageObject.GetScale());
		pStageObject->SetType(loadStageObject.GetType());
		ADDOBJECT(pStageObject);*/


	}
	fclose(pFile);
}

list<CGameObject*>& CScene::GetLayerObject(Layer layer)
{
	return m_listObj[(int)layer];
}

void CScene::AddGameObject(CGameObject* pGameObj)
{
	// ���ο� ���ӿ�����Ʈ �߰� �� �ʱ�ȭ
	m_listObj[(int)pGameObj->GetLayer()].push_back(pGameObj);
	pGameObj->GameObjectInit();
}

void CScene::DeleteLayerObject(Layer layer)
{
	for (CGameObject* pObj : m_listObj[(int)layer])
	{
		delete pObj;
	}
	m_listObj[(int)layer].clear();
}

void CScene::DeleteAll()
{
	for (int i = 0; i < (UINT)Layer::Size; i++)
	{
		DeleteLayerObject((Layer)i);
	}
}

