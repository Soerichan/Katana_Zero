#pragma once
#include "framework.h"
class CareTaker
{
public: CareTaker() {};
 ~CareTaker(){};

 //void Addcam(Memento Vector) 
 //{
	// m_vector_Camera_Memento.push_back(Vector);
 //}
 //Memento Popcam()
 //{
	// return m_vector_Camera_Memento.back();
 //}
 void Addplayer(Memento* Vector)
 {
	 m_vector_Player_Memento.push_back(Vector);
 }
 Memento* Popplayer()
 {
	 Memento* ret = m_vector_Player_Memento.back();
	 m_vector_Player_Memento.pop_back();
	 return ret;
 }

 bool IsEmpty() { return m_vector_Player_Memento.empty(); }

private:
	/*vector<Memento> m_vector_Camera_Memento;*/
	vector<Memento*> m_vector_Player_Memento;

}; 