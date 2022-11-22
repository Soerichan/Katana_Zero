#pragma once
#include "CScene.h"
class CScene_file :
    public CScene
{
public:
	CScene_file();
	virtual ~CScene_file();

private:
	CImage* pImage01;
	CImage* pImage02;
	CImage* pImage03;
	CSound* m_pPaperSound;
	CSound* m_pZippoSound;
	CSound* m_pFireSound;
	bool m_bFire;
	float m_fFireTimer;
	bool m_bZippoSound;
	bool m_bFireSound;

	void Init()		override;
	void Enter()	override;
	void Update()	override;
	void Render()	override;
	void Exit()		override;
	void Release()	override;
};

