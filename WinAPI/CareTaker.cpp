#include "framework.h"
#include "CareTaker.h"

CareTaker::CareTaker()
{
}

CareTaker::~CareTaker()
{
}

void CareTaker::Addplayer(Memento* Vector)
{
	m_vector_Player_Memento.push_back(Vector);
}

Memento* CareTaker::Popplayer()
{	
	
	Memento* ret = m_vector_Player_Memento.back();
	m_vector_Player_Memento.pop_back();
	return ret;
}

bool CareTaker::IsEmpty()
{
	return m_vector_Player_Memento.empty();
}
