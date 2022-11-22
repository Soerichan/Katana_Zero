#pragma once
#include "CSound.h"
class BGM_Main :
    public CSound
{
public:
	BGM_Main();
	virtual ~BGM_Main();
	FMOD::Sound* GetBGM_Main();

};

