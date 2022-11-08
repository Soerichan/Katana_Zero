#pragma once
#include "CStageObject.h"
class CPlatfoam :
    public CStageObject
{
public:
	CPlatfoam();
	virtual ~CPlatfoam();

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

