#pragma once //Run once
#include "Character.h"

/*
	Does not require anymore includes as it already includes its 
	parent class and so therefore will gain all the includes the parent
	already has
*/

class Monster : public Character //Inheritance, child of character class
{
	private:
		int m_Health; //Monsters Total Health
		int m_S_Range; //Monsters Sight Range
		int m_A_Range; //Monsters Attack Range
		int m_Damage; //Monster Damage
		bool m_Alert; //Trigger for when monster sees the main character
		bool SwitchRight; //Tells Monster to go right instead
	public:
		Monster(int xpos,int ypos,string name,string filename,double M_speed,int S_range,int Health,int A_range,int Damage); //Constructor
		~Monster(); //Destructor
		void Roam(); //Method that makes the monster roam
		void Caught(int MC_xpos,int MC_ypos); //Method to switch monster to alert status

};