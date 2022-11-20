#pragma once
#include "CScene.h"
class CPlayer;
class CScene001 :
    public CScene
{
public:


	CScene001();
	virtual ~CScene001();


private:
	CPlayer* pPlayer;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

