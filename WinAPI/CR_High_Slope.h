#pragma once
#include "CStageObject.h"
class CR_High_Slope :
    public CStageObject
{
public:
	CR_High_Slope();
	virtual ~CR_High_Slope();

private:


	void Init() override;
	void Update() override;
	void Render() override;
	void Release() override;

private:
	void OnCollisionEnter(CCollider* pOther) override;
	void OnCollisionStay(CCollider* pOther) override;
	void OnCollisionExit(CCollider* pOther) override;

};

