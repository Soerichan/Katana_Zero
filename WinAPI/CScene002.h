#pragma once
#include "CScene.h"
class CPlayer;
class CScene002 :
    public CScene
{
public:


	CScene002();
	virtual ~CScene002();


private:
	CPlayer* pPlayer;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

