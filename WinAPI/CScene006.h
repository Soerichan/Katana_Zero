#pragma once
#include "CScene.h"
class CPlayer;
class CScene006 :
    public CScene
{
public:


	CScene006();
	virtual ~CScene006();


private:
	CPlayer* pPlayer;
	float m_fDeadMonsterCount006;

	bool m_bSoundChange;
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

