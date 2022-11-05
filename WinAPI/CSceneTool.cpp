#include "framework.h"
#include "CSceneTool.h"

LRESULT CALLBACK    WinTileToolProc(HWND, UINT, WPARAM, LPARAM);

CSceneTool::CSceneTool()
{
	m_hWndStageObjectTool = 0;
	m_pImageObj = nullptr;

	m_fScrollSpeed = 300;

	m_uiStageObjectPanelPage = 0;
	m_uiStageObjectCountX = 0;
	m_uiStageObjectCountY = 0;
	m_uiSelectedStageObjectIndex = 0;
	m_typeSelectedStageObjectType = TypeStageObject::None;
	
}

CSceneTool::~CSceneTool()
{
}



void CSceneTool::StartSetStageObjects(TypeStageObject type)
{
	vecToolMousePos = MOUSEWORLDPOS;
	if (LMOUSEUP(false))
	{	
		vecToolMousePos2 = MOUSEWORLDPOS;
		SetStageObjects(type);
	}
}

void CSceneTool::SetStageObjects(TypeStageObject type)
{
	
	CStageObject* newObject = new CStageObject;
	newObject->SetPos(vecToolMousePos, vecToolMousePos2);
	ADDOBJECT(newObject);
	
}

void CSceneTool::DeleteStageObjects()
{

}

void CSceneTool::CameraMove()
{
	Vector dir;
	if (BUTTONSTAY('A'))
	{
		dir.x = -1;
	}
	else if (BUTTONSTAY('D'))
		dir.x = 1;
	else dir.x = 0;

	if (BUTTONSTAY('W'))
		dir.y = -1;
	else if (BUTTONSTAY('S'))
		dir.y = 1;
	else
		dir.y = 0;

	CAMERA->Scroll(dir, m_fScrollSpeed);
}

void CSceneTool::SaveStageObject(const wstring& strPath)
{

}

void CSceneTool::SaveStageObjectData()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);  // 구조체 사이즈.
	ofn.hwndOwner = hWnd;					// 부모 윈도우 지정.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName; // 나중에 완성된 경로가 채워질 버퍼 지정.
	ofn.nMaxFile = sizeof(szName); // lpstrFile에 지정된 버퍼의 문자 수.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // 필터 설정
	ofn.nFilterIndex = 0; // 기본 필터 세팅. 0는 all로 초기 세팅됨. 처음꺼.
	ofn.lpstrFileTitle = nullptr; // 타이틀 바
	ofn.nMaxFileTitle = 0; // 타이틀 바 문자열 크기. nullptr이면 0.
	wstring strTileFolder = GETPATH;
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str(); // 초기경로. 우리는 타일 저장할거기 때문에, content->tile 경로로 해두자.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 스타일

	if (GetSaveFileName(&ofn))
	{
		SaveStageObject(szName);
	}
}

void CSceneTool::LoadStageObject(const wstring& strPath)
{

}

void CSceneTool::LoadStageObjectData()
{
	OPENFILENAME ofn = {};

	ofn.lStructSize = sizeof(OPENFILENAME);  // 구조체 사이즈.
	ofn.hwndOwner = hWnd; // 부모 윈도우 지정.
	wchar_t szName[256] = {};
	ofn.lpstrFile = szName; // 나중에 완성된 경로가 채워질 버퍼 지정.
	ofn.nMaxFile = sizeof(szName); // lpstrFile에 지정된 버퍼의 문자 수.
	ofn.lpstrFilter = L"ALL\0*.*\0tile\0*.tile"; // 필터 설정
	ofn.nFilterIndex = 0; // 기본 필터 세팅. 0는 all로 초기 세팅됨. 처음꺼.
	ofn.lpstrFileTitle = nullptr; // 타이틀 바
	ofn.nMaxFileTitle = 0; // 타이틀 바 문자열 크기. nullptr이면 0.
	wstring strTileFolder = GETPATH;
	strTileFolder += L"tile";
	ofn.lpstrInitialDir = strTileFolder.c_str(); // 초기경로. 우리는 타일 저장할거기 때문에, content->tile 경로로 해두자.
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST; // 스타일

	if (GetOpenFileName(&ofn))
	{
		LoadTile(szName);
	}
}



void CSceneTool::SaveMap(const wstring& strPath)
{
}

void CSceneTool::SaveMapData()
{
}

void CSceneTool::LoadMap(const wstring& strPath)
{
}

void CSceneTool::LoadMapData()
{
}

void CSceneTool::Init()
{
}

void CSceneTool::Enter()
{
}

void CSceneTool::Update()
{
	if (BUTTONDOWN(VK_ESCAPE))
	{
		CHANGESCENE(GroupScene::Title);
	}

	if (LMOUSESTAY(false))
	{
		StartSetStageObjects(TypeStageObject type);
	}
	if (RMOUSESTAY(false))
	{
		DeleteStageObjects();
	}
	CameraMove();
}

void CSceneTool::Render()
{
}

void CSceneTool::Exit()
{
}

void CSceneTool::Release()
{
}
