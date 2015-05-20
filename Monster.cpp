#include "Monster.h"

Monster::Monster(int xpos,int ypos,string name,string filename,double M_speed,int S_range,int Health, int A_range,int Damage) : Character(name,filename,xpos,ypos,M_speed)
{
	m_Health = Health;
	m_S_Range = S_range;
	m_A_Range = A_range;
	m_Damage = Damage;
	bool m_Alert = false;
}

void Monster::Roam()
{
	//Add if collision here which will set the the switchRight true or false

	if(SwitchRight)
	{
		Character::right();
	}

	else
	{
		Character::left();
	}
}

void Monster::Caught(int MC_xpos, int MC_ypos)
{
	if(SwitchRight)
	{
		if((Character::getXpos() + m_S_Range) > MC_xpos 
			&& Character::getYpos() == MC_ypos)
		{
			m_Alert = true;
		}
	}
	else
	{
		if((Character::getXpos() - m_S_Range) < MC_xpos 
			&& Character::getYpos() == MC_ypos)
		{
			m_Alert = true;
		}
	}

}