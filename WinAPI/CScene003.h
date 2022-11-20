#pragma once
#include "CScene.h"
class CPlayer;
class CScene003 :
    public CScene
{
public:


	CScene003();
	virtual ~CScene003();


private:
	CPlayer* pPlayer;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

