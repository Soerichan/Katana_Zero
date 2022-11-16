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
}

void CBattery::Render()
{
	RENDER->Image(pFullImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 1280, m_vecRenderPos.y + 46);

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
