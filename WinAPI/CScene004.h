#pragma once
#include "CScene.h"
class CPlayer;
class CScene004 :
    public CScene
{
public:


	CScene004();
	virtual ~CScene004();


private:
	CPlayer* pPlayer;
	float m_fDeadMonsterCount004;
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

