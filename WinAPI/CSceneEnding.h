#pragma once
#include "CScene.h"
class CSceneEnding :
    public CScene
{
public:

	CSceneEnding();
	virtual ~CSceneEnding();


private:
	CSound* m_pEndSound;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

