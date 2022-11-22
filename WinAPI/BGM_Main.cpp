#include "framework.h"
#include "BGM_Main.h"

BGM_Main::BGM_Main()
{
	//m_pSound = RESOURCE->LoadSound(L"BGM_Main", L"Sound\\BGM");
}

BGM_Main::~BGM_Main()
{
}

FMOD::Sound* BGM_Main::GetBGM_Main()
{
	return m_pSound;
}
