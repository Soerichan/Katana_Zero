#include "framework.h"
#include "CSceneTool.h"

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
