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
	// 씬 내에 모든 게임오브젝트 초기화
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectInit();
		}
	}

	// 상속한 자식 초기화
	Init();
}

void CScene::SceneEnter()
{
	// 이전 씬의 카메라 상황을 초기화하고 카메라의 위치를 초기 위치로
	// 씬의 카메라 시작위치가 초기 위치가 아닌경우 씬의 Enter에서 위치를 설정하여 목표위치가 덮어씀
	CAMERA->SetTargetObj(nullptr);
	CAMERA->SetTargetPos(Vector(WINSIZEX * 0.5f, WINSIZEY * 0.5f));
	externCareTaker.PopClear();
	GAME->LaserOff = false;
	Enter();
}

void CScene::SceneUpdate()
{
	// 씬 내에 삭제해도 안전한 게임오브젝트를 삭제
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

	// 씬 내에 모든 게임오브젝트 로직갱신
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

	// 상속한 자식 로직갱신
	Update();
}

void CScene::ScenePhysicsUpdate()
{
	// 씬 내에 모든 게임오브젝트 물리처리 진행
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
	// 씬 내에 모든 게임오브젝트 표현갱신
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

	// 상속한 자식 표현갱신
	Render();
}

void CScene::SceneExit()
{
	Exit();
}

void CScene::SceneRelease()
{
	// 씬 내에 모든 게임오브젝트 마무리
	for (int layer = 0; layer < (int)Layer::Size; layer++)
	{
		for (CGameObject* pGameObject : m_listObj[layer])
		{
			pGameObject->GameObjectRelease();
			delete pGameObject;
		}
		m_listObj[layer].clear();
	}

	// 상속한 자식 마무리
	Release();
}

void CScene::StageObjectRender()
{
	// 게임 화면에 표시되지 않는 타일은 랜더링을 진행하지 않음
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

	//	// TODO : 타일 타입에 따른 생성
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
	// 새로운 게임오브젝트 추가 및 초기화
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

