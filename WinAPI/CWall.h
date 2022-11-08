#pragma once
#include "CStageObject.h"
class CWall :
    public CStageObject
{
public:
	CWall();
	virtual ~CWall();

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

