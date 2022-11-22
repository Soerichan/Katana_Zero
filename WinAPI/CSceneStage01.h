#pragma once
#include "CScene.h"

class CPlayer;

class CSceneStage01 : public CScene
{
public:
	CSceneStage01();
	virtual ~CSceneStage01();
	


private:
	CPlayer* pPlayer;
	float m_fDeadMonsterCount007;
	//CImage* pSubWeapon_Bottle;


private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};
