#include "framework.h"
#include "CPlayer.h"
#include "CAnimation.h"
#include "CAnimator.h"
#include "Memento.h"

Memento::Memento()
{
}

Memento::~Memento()
{
}

void Memento::SetPlayerMemento(CPlayer* pl)
{
	
		
		this->VectorMemento =pl->GetPos();
		this->AnimationMemento = pl->GetAnimator()->GetCurAnimation();
		this->CurFrameMemento = pl->GetAnimator()->GetCurAnimation()->GetCurFrame();
		
	
}

Vector Memento::GetVectorMemento()
{
	 return this->VectorMemento; 
}

CAnimation* Memento::GetAnimationMemento()
{
	 return this->AnimationMemento; 
}

UINT Memento::GetCurFrameMemento()
{
	return this->CurFrameMemento;
}
