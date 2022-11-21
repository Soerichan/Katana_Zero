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
	
	
	
	return m_vector_Player_Memento.back();
}

void CareTaker::PopDelete()
{
	m_vector_Player_Memento.pop_back();
}

bool CareTaker::IsEmpty()
{
	return m_vector_Player_Memento.empty();
}
