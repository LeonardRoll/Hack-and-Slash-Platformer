#include "Main_Char.h"

Main_Char::Main_Char(int xpos,int ypos,string name,string filename,double M_speed, int lives) : Character(name,filename,xpos,ypos,M_speed)
{
	m_Lives = lives;
	m_Score = 0; // Set score to zero
}

void Main_Char::debug()
{
	cout << "Lives: " << m_Lives << endl;
	cout << "Score: " << m_Score << endl;
}

void Main_Char::draw_Hero(){Character::Character_Draw();}

void Main_Char::reduce_Life(){m_Lives--;}
void Main_Char::increase_Life(){m_Lives++;}
int Main_Char::get_Life(){return m_Lives;}

void Main_Char::damage_Health(int damage){m_Health = m_Health - damage;}

bool Main_Char::check_Death()
{
	if(m_Health <= 0)
		return true;
	else
		return false;
}

void Main_Char::set_Speed(double M_speed){m_M_speed = M_speed;}
void Main_Char::add_Score(int amount){m_Score = m_Score + amount;}
void Main_Char::reduce_Score(int amount){m_Score = m_Score - amount;}
int Main_Char::get_Score(){return m_Score;}