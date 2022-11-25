#pragma once
#include "CGameObject.h"
class CImage;
class CCronosEffect :
    public CGameObject
{
public:
	CCronosEffect();
	virtual ~CCronosEffect();

	
private:
	CImage* m_pImage;
	

	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;



};

