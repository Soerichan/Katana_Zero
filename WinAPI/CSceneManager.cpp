#include "framework.h"
#include "CSceneManager.h"

#include "CScene.h"
#include "CSceneTitle.h"
#include "CSceneTileTool.h"
#include "CSceneStage01.h"
#include "CScene_file.h"
#include "CScene000.h"
#include "CScene001.h"
#include "CScene002.h"
#include "CScene003.h"
#include "CScene004.h"
#include "CScene005.h"
#include "CScene006.h"
#include "CSceneEnding.h"

CSceneManager::CSceneManager()
{
	m_pCurScene = nullptr;
}

CSceneManager::~CSceneManager()
{
}

void CSceneManager::Init()
{
	// TODO : ���ӿ� �ʿ��� �� �߰�
	// ���Ӿ����� �ڷᱸ���� �߰�
	CScene* pSceneTitle = new CSceneTitle();
	m_mapScene.insert(make_pair(GroupScene::Title, pSceneTitle));
	CSceneTileTool* pSceneTileTool = new CSceneTileTool;
	m_mapScene.insert(make_pair(GroupScene::TileTool, pSceneTileTool));
	CScene* pSceneStage01 = new CSceneStage01();
	m_mapScene.insert(make_pair(GroupScene::Stage01, pSceneStage01));
	CScene* pScene_file = new CScene_file();
	m_mapScene.insert(make_pair(GroupScene::Scene_file, pScene_file));
	CScene* pScene000 = new CScene000();
	m_mapScene.insert(make_pair(GroupScene::Scene000, pScene000));
	CScene* pScene001 = new CScene001();
	m_mapScene.insert(make_pair(GroupScene::Scene001, pScene001));
	CScene* pScene002 = new CScene002();
	m_mapScene.insert(make_pair(GroupScene::Scene002, pScene002));
	CScene* pScene003 = new CScene003();
	m_mapScene.insert(make_pair(GroupScene::Scene003, pScene003));
	CScene* pScene004 = new CScene004();
	m_mapScene.insert(make_pair(GroupScene::Scene004, pScene004));
	CScene* pScene005 = new CScene005();
	m_mapScene.insert(make_pair(GroupScene::Scene005, pScene005));
	CScene* pScene006 = new CScene006();
	m_mapScene.insert(make_pair(GroupScene::Scene006, pScene006));
	CScene* pEnd = new CSceneEnding();
	m_mapScene.insert(make_pair(GroupScene::SceneEnding, pEnd));





	// ���Ӿ� �ڷᱸ���� ��ȸ�ϸ� ���� �ʱ�ȭ
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneInit();
	}

	// ���� ó������ �����ؾ��� ���Ӿ� ����
	m_pCurScene = pSceneTitle;
	m_pCurScene->SceneEnter();
}

void CSceneManager::Update()
{
	m_pCurScene->SceneUpdate();
	m_pCurScene->ScenePhysicsUpdate();
}

void CSceneManager::Render()
{
	m_pCurScene->SceneRender();
}

void CSceneManager::Release()
{
	// ���Ӿ� �ڷᱸ���� ��ȸ�ϸ� �����Ҵ�� ���� ����
	for (pair<GroupScene, CScene*> scene : m_mapScene)
	{
		scene.second->SceneRelease();
		delete scene.second;
	}
	
	// ��� �����Ҵ�� ���� �����ѵ� �ڷᱸ���� clear
	m_mapScene.clear();
}

void CSceneManager::ChangeScene(GroupScene scene)
{
	// �������� Exit, �������� Enter
	m_pCurScene->SceneExit();
	m_pCurScene = m_mapScene[scene];
	m_pCurScene->SceneEnter();
}

CScene* CSceneManager::GetCurScene()
{
	return m_pCurScene;
}
