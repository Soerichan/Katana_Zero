#include "framework.h"
#include "CHUD.h"
#include "CSpark.h"

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

	pSubWeaponImage = RESOURCE->LoadImg(L"SubWeapon", L"Image\\UI\\SubWeapon.png");
	pSubWeapon_NoneImage = RESOURCE->LoadImg(L"SubWeapon_None", L"Image\\UI\\SubWeapon_None.png");
	pSubWeapon_Bottle01Image = RESOURCE->LoadImg(L"SubWeapon_Bottle01", L"Image\\UI\\SubWeapon_Bottle01.png");
	pSubWeapon_Bottle02Image = RESOURCE->LoadImg(L"SubWeapon_Bottle02", L"Image\\UI\\SubWeapon_Bottle02.png");
	pSubWeapon_Bottle03Image = RESOURCE->LoadImg(L"SubWeapon_Bottle03", L"Image\\UI\\SubWeapon_Bottle03.png");
	pSubWeapon_BucherImage = RESOURCE->LoadImg(L"SubWeapon_Butcher", L"Image\\UI\\SubWeapon_Butcher.png");
	pSubWeapon_KnifeImage = RESOURCE->LoadImg(L"SubWeapon_Knife", L"Image\\UI\\SubWeapon_Knife.png");
	pSubWeapon_PotImage = RESOURCE->LoadImg(L"SubWeapon_Pot", L"Image\\UI\\SubWeapon_Pot.png");
	pSubWeapon_StatueImage = RESOURCE->LoadImg(L"SubWeapon_Statue", L"Image\\UI\\SubWeapon_Statue.png");
	pSubWeapon_SmokerImage = RESOURCE->LoadImg(L"SubWeapon_Smoke", L"Image\\UI\\SubWeapon_Smoker.png");
	pSubWeapon_LampImage = RESOURCE->LoadImg(L"SubWeapon_Lamp", L"Image\\UI\\SubWeapon_Lamp.png");
	pSubWeapon_Mine01Image = RESOURCE->LoadImg(L"SubWeapon_Mine01", L"Image\\UI\\SubWeapon_Mine01.png");
	pSubWeapon_Mine02Image = RESOURCE->LoadImg(L"SubWeapon_Mine02", L"Image\\UI\\SubWeapon_Mine02.png");

	CronosBG= RESOURCE->LoadImg(L"CronosBG", L"Image\\UI\\CronosBG.png");
	ReplayBG = RESOURCE->LoadImg(L"ReplayBG", L"Image\\UI\\ReplayBG.png");


	m_bScreenFixed = true;

}

void CHUD::Update()
{
	Dischared = 11 - GAME->Battery;
	m_fTimer -= TIME->GetRealTime();

	/*if (Dischared < 10)
	{
		CSpark* pSpark = new CSpark;
		pSpark->SetPos(m_vecRenderPos.x + 154, m_vecRenderPos.y + 42);
		pSpark->SetxDir(1);
		ADDOBJECT(pSpark);
	}*/
}

void CHUD::Render()
{
	
	if (GAME->isCronos)
	{
		RENDER->Image(CronosBG, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 1280, m_vecRenderPos.y + 720);
	}

	/*if (GAME->isReplay)
	{
		RENDER->Image(ReplayBG, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 1280, m_vecRenderPos.y + 720);
	}*/
	//RENDER->FrameImage(pDischargedBatteryImage, 130 - 20*Dischared, m_vecRenderPos.y, m_vecRenderPos.x + 154, m_vecRenderPos.y + 38
	//	, 130 - 20*Dischared, 0, 154,38);

	//허브
	RENDER->Image(pImage, m_vecRenderPos.x, m_vecRenderPos.y, m_vecRenderPos.x + 1280, m_vecRenderPos.y + 46);

	//시간타이머
	RENDER->Image(pTimerImage, m_vecRenderPos.x + 529, m_vecRenderPos.y + 4, m_vecRenderPos.x + 751, m_vecRenderPos.y + 42);
	RENDER->FrameImage(pTimerTimeImage, m_vecRenderPos.x + 529, m_vecRenderPos.y + 4, m_vecRenderPos.x + 751-(2*(90.f-m_fTimer)), m_vecRenderPos.y + 42, 0, 0, 223 - (2 * (90.f - m_fTimer)), 38);


	//서브웨폰
	if (GAME->SubWeaponName == L"None")
	{
		RENDER->Image(pSubWeapon_NoneImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Bottle01")
	{
		RENDER->Image(pSubWeapon_Bottle01Image, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Bottle02")
	{
		RENDER->Image(pSubWeapon_Bottle02Image, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Bottle03")
	{
		RENDER->Image(pSubWeapon_Bottle03Image, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Butcher")
	{
		RENDER->Image(pSubWeapon_BucherImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Knife")
	{
		RENDER->Image(pSubWeapon_KnifeImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Pot")
	{
		RENDER->Image(pSubWeapon_PotImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Statue")
	{
		RENDER->Image(pSubWeapon_StatueImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Smoker")
	{
		RENDER->Image(pSubWeapon_SmokerImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Lamp")
	{
		RENDER->Image(pSubWeapon_LampImage, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Mine01")
	{
		RENDER->Image(pSubWeapon_Mine01Image, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	else if (GAME->SubWeaponName == L"Mine02")
	{
		RENDER->Image(pSubWeapon_Mine02Image, m_vecRenderPos.x + 1153, m_vecRenderPos.y + 4, m_vecRenderPos.x + 1265, m_vecRenderPos.y + 52);
	}
	

	//배터리
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
