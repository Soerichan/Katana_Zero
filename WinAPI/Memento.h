#pragma once
//#include "framework.h"
//#include "CPlayer.h"
//#include "CAnimation.h"
//#include "CAnimator.h"
class CPlayer;
class CAnimation;

class Memento
{

public:
	Memento();
		~Memento();

	/*void SetcameraVector(Vector cam) { this->cameraVector = cam; };*/

	//void SetPlayerVector(Vector pl) { this->PlayerVector = pl; }
		void SetPlayerMemento(CPlayer* pl);
	
	//Vector GetPlayerVector() { return this->PlayerVector; }
	//CPlayer* GetPlayerMemento() { return this->PlayerMemento; }
		Vector GetVectorMemento();
		CAnimation* GetAnimationMemento();
		UINT GetCurFrameMemento();

private:

	/*Vector cameraVector;*/
	//Vector PlayerVector;
	//CPlayer* PlayerMemento;
	Vector VectorMemento;
	CAnimation* AnimationMemento;
	UINT CurFrameMemento;


	//Vector MonsterVector;
	//wstring PlayerAnimation;

	
};