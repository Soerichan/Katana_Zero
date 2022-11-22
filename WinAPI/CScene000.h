#pragma once
#include "CScene.h"
class CPlayer;

class CScene000 :
    public CScene
{
public:


	CScene000();
	virtual ~CScene000();


	
private:
	CPlayer* pPlayer;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

