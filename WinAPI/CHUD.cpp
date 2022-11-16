#include "framework.h"
#include "CHUD.h"

CHUD::CHUD()
{
	pImage = nullptr;
}

CHUD::~CHUD()
{
}

void CHUD::Init()
{
	pImage= RESOURCE->LoadImg(L"HUD", L"Image\\UI\\HUD.png");
	m_bScreenFixed = true;
}

void CHUD::Update()
{
}

void CHUD::Render()
{
	RENDER->Image(pImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x+1280, m_vecRenderPos.y+46);
}

void CHUD::Release()
{
}

void CHUD::OnMouseEnter()
{
}

void CHUD::OnMouseOver()
{
}

void CHUD::OnMouseExit()
{
}

void CHUD::OnMouseUp()
{
}

void CHUD::OnMouseDown()
{
}

void CHUD::OnMouseClicked()
{
}
