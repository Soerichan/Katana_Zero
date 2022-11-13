#pragma once
#include "CScene.h"
#include "CTitle_Layer01.h"
#include "CTitle_Layer02.h"
#include "CTitle_Layer03.h"
#include "CTitle_Layer04.h"

class CSceneTitle : public CScene
{
public:
	CSceneTitle();
	virtual ~CSceneTitle();

private:
	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;

	CTitle_Layer01* m_pLayer01;
	CTitle_Layer02* m_pLayer02;
	CTitle_Layer03* m_pLayer03;
	CTitle_Layer04* m_pLayer04;
};
