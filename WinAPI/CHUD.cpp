#include "framework.h"
#include "CHUD.h"

CHUD::CHUD()
{
	pImage = nullptr;
	pFullBatteryImage = nullptr;
	//pDischargedBatteryImage = nullptr;
	Dischared = 0;
	m_fTimer = 90.f;
}

CHUD::~CHUD()
{
}

void CHUD::Init()
{
	pImage= RESOURCE->LoadImg(L"HUD", L"Image\\UI\\HUD.png");

	pFullBatteryImage = RESOURCE->LoadImg(L"FullBattery", L"Image\\UI\\Battery.png");
	pDischargedBatteryImage = RESOURCE->LoadImg(L"DischargedBattery", L"Image\\UI\\Battery_Discharged.png");
	pDischargedBattery1Image = RESOURCE->LoadImg(L"DischargedBattery1", L"Image\\UI\\Battery_Discharged_1.png");
	pDischargedBattery2Image = RESOURCE->LoadImg(L"DischargedBattery2", L"Image\\UI\\Battery_Discharged_2.png");
	pDischargedBattery3Image = RESOURCE->LoadImg(L"DischargedBattery3", L"Image\\UI\\Battery_Discharged_3.png");
	pDischargedBattery4Image = RESOURCE->LoadImg(L"DischargedBattery4", L"Image\\UI\\Battery_Discharged_4.png");
	pDischargedBattery5Image = RESOURCE->LoadImg(L"DischargedBattery5", L"Image\\UI\\Battery_Discharged_5.png");
	pDischargedBattery6Image = RESOURCE->LoadImg(L"DischargedBattery6", L"Image\\UI\\Battery_Discharged_6.png");
	pDischargedBattery7Image = RESOURCE->LoadImg(L"DischargedBattery7", L"Image\\UI\\Battery_Discharged_7.png");
	pDischargedBattery8Image = RESOURCE->LoadImg(L"DischargedBattery8", L"Image\\UI\\Battery_Discharged_8.png");
	pDischargedBattery9Image = RESOURCE->LoadImg(L"DischargedBattery9", L"Image\\UI\\Battery_Discharged_9.png");
	pDischargedBattery10Image = RESOURCE->LoadImg(L"DischargedBattery10", L"Image\\UI\\Battery_Discharged_10.png");
	pDischargedBattery11Image = RESOURCE->LoadImg(L"DischargedBattery11", L"Image\\UI\\Battery_Discharged_11.png");

	pTimerImage = RESOURCE->LoadImg(L"Timer", L"Image\\UI\\Timer.png");
	pTimerTimeImage = RESOURCE->LoadImg(L"TimerTime", L"Image\\UI\\Timer_Time.png");

	


	m_bScreenFixed = true;
	
}

void CHUD::Update()
{
	Dischared = 11 - GAME->Battery;
	m_fTimer -= TIME->GetRealTime();
}

void CHUD::Render()
{
	
	
	//RENDER->FrameImage(pDischargedBatteryImage, 130 - 20*Dischared, m_vecRenderPos.y, m_vecRenderPos.x + 154, m_vecRenderPos.y + 38
	//	, 130 - 20*Dischared, 0, 154,38);

	RENDER->Image(pImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 1280, m_vecRenderPos.y + 46);

	RENDER->Image(pTimerImage, m_vecRenderPos.x + 529, m_vecRenderPos.y + 4, m_vecRenderPos.x + 751, m_vecRenderPos.y + 42);
	RENDER->FrameImage(pTimerTimeImage, m_vecRenderPos.x + 529, m_vecRenderPos.y + 4, m_vecRenderPos.x + 751-(2*(90.f-m_fTimer)), m_vecRenderPos.y + 42, 0, 0, 223 - (2 * (90.f - m_fTimer)), 38);


	switch (Dischared)
	{
	case 0:
		RENDER->Image(pFullBatteryImage, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 1:
		RENDER->Image(pDischargedBattery1Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 2:
		RENDER->Image(pDischargedBattery2Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;

	case 3:
		RENDER->Image(pDischargedBattery3Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break; 
	case 4:
		RENDER->Image(pDischargedBattery4Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 5:
		RENDER->Image(pDischargedBattery5Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 6:
		RENDER->Image(pDischargedBattery6Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 7:
		RENDER->Image(pDischargedBattery7Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 8:
		RENDER->Image(pDischargedBattery8Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 9:
		RENDER->Image(pDischargedBattery9Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 10:
		RENDER->Image(pDischargedBattery10Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	case 11:
		RENDER->Image(pDischargedBattery11Image, m_vecRenderPos.x, m_vecRenderPos.y+4, m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		break;
	}
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
