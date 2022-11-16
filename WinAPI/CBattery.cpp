#include "framework.h"
#include "CBattery.h"

CBattery::CBattery()
{
	pFullImage = nullptr;
	pDischargedImage = nullptr;
}

CBattery::~CBattery()
{
}

void CBattery::Init()
{
	pFullImage = RESOURCE->LoadImg(L"HUD", L"Image\\UI\\Battery.png");
	pDischargedImage = RESOURCE->LoadImg(L"HUD", L"Image\\UI\\Battery_Discharged.png");
	m_bScreenFixed = true;
}

void CBattery::Update()
{
	Dischared = 11-GAME->Battery;
}

void CBattery::Render()
{
	RENDER->Image(pFullImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 154, m_vecRenderPos.y + 38);
	RENDER->FrameImage(pDischargedImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 154, m_vecRenderPos.y + 38
		, 120 - Dischared, 120, 0, 30);

}

void CBattery::Release()
{
}

void CBattery::OnMouseEnter()
{
}

void CBattery::OnMouseOver()
{
}

void CBattery::OnMouseExit()
{
}

void CBattery::OnMouseUp()
{
}

void CBattery::OnMouseDown()
{
}

void CBattery::OnMouseClicked()
{
}
