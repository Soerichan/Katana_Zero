#pragma once
#include "CScene.h"
class CPlayer;
class CScene005 :public CScene
{
public:


	CScene005();
	virtual ~CScene005();


private:
	CPlayer* pPlayer;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

