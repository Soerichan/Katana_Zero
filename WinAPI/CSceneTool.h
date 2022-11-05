#pragma once
#include "CScene.h"

class CImageObject;

class CSceneTool :
    public CScene
{
	friend CStageObject;
	
	public:
		CSceneTool();
		virtual ~CSceneTool();
	

	private:
		HWND m_hWndStageObjectTool;
		CImageObject* m_pImageObj;
		float m_fScrollSpeed;

		UINT m_uiStageObjectPanelPage;
		UINT m_uiStageObjectCountX;
		UINT m_uiStageObjectCountY;

		UINT m_uiSelectedStageObjectIndex;
		TypeStageObject m_typeSelectedStageObjectType;
		

	private:

		void StartSetStageObjects( TypeStageObject type);
		void SetStageObjects(TypeStageObject type);
		void DeleteStageObjects();
		

		void CameraMove();

	public:

		void SaveStageObject(const wstring& strPath);
		void SaveStageObjectData();
		void LoadStageObject(const wstring& strPath);
		void LoadStageObjectData();
		void SaveMap(const wstring& strPath);
		void SaveMapData();
		void LoadMap(const wstring& strPath);
		void LoadMapData();

		//void ClickStageObjectButton(UINT index);
		//void ClickStageObjectType(TypeStageObject type);

	private:
		void Init() override;
		void Enter() override;
		void Update() override;
		void Render() override;
		void Exit() override;
		void Release() override;
	
};

