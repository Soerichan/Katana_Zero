#pragma once

class CareTaker
{
public: CareTaker();
	  ~CareTaker();

 //void Addcam(Memento Vector) 
 //{
	// m_vector_Camera_Memento.push_back(Vector);
 //}
 //Memento Popcam()
 //{
	// return m_vector_Camera_Memento.back();
 //}
	  void Addplayer(Memento* Vector);

 //void AddplayerMemento(Memento* Player)
 //{
	// m_vector_Player_Memento.push_back(Player);
 //}

 Memento* Popplayer();
 void PopDelete();
 void PopClear();

 bool IsEmpty();

private:
	/*vector<Memento> m_vector_Camera_Memento;*/
	vector<Memento*> m_vector_Player_Memento;

}; 