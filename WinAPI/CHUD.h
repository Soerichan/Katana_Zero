#pragma once
#include "CUI.h"
class CImage;

class CHUD :
    public CUI
{
public:
	CHUD();
	virtual ~CHUD();
	
	CImage* pImage;


	CImage* pFullBatteryImage;
	CImage* pDischargedBatteryImage;
	CImage* pDischargedBattery1Image;
	CImage* pDischargedBattery2Image;
	CImage* pDischargedBattery3Image;
	CImage* pDischargedBattery4Image;
	CImage* pDischargedBattery5Image;
	CImage* pDischargedBattery6Image;
	CImage* pDischargedBattery7Image;
	CImage* pDischargedBattery8Image;
	CImage* pDischargedBattery9Image;
	CImage* pDischargedBattery10Image;
	CImage* pDischargedBattery11Image;

	CImage* pTimerImage;
	CImage* pTimerTimeImage;

	CImage* pSubWeaponImage;
	CImage* pSubWeapon_NoneImage;
	CImage* pSubWeapon_Bottle01Image;
	CImage* pSubWeapon_Bottle02Image;
	CImage* pSubWeapon_Bottle03Image;
	CImage* pSubWeapon_BucherImage;
	CImage* pSubWeapon_KnifeImage;
	CImage* pSubWeapon_PotImage;
	CImage* pSubWeapon_StatueImage;
	CImage* pSubWeapon_SmokeImage;
	CImage* pSubWeapon_LampImage;
	CImage* pSubWeapon_Mine01Image;
	CImage* pSubWeapon_Mine02Image;

	float m_fTimer;

	

	int Dischared;

private:
	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

	virtual void OnMouseEnter()override;
	virtual void OnMouseOver()override;
	virtual void OnMouseExit() override;
	virtual void OnMouseUp() override;
	virtual void OnMouseDown() override;
	virtual void OnMouseClicked() override;
};

