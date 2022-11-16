#pragma once
#include "CUI.h"
class CBattery :
    public CUI
{
public:
	CBattery();
	virtual ~CBattery();

	CImage* pFullImage;
	CImage* pDischargedImage;

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

