#pragma once
#include "framework.h"

class Memento
{

public:
	Memento(){};
	~Memento(){};

	/*void SetcameraVector(Vector cam) { this->cameraVector = cam; };*/

	void SetPlayerVector(Vector pl) { this->PlayerVector = pl; }
	Vector GetPlayerVector() { return this->PlayerVector; }

private:

	/*Vector cameraVector;*/
	Vector PlayerVector;

	//Vector MonsterVector;
	//wstring PlayerAnimation;

	
};