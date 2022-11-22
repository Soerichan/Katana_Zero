#pragma once
#include "CImageObject.h"
class CNoAttack :
    public CImageObject
{
public: CNoAttack();
	  virtual ~CNoAttack();


private:
	float m_fTimer;

	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

};

