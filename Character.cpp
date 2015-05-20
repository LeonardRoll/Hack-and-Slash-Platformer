#include "Character.h"

Character::Character(string name, string filename, int spawnX, int spawnY, double M_speed)
{
	m_name = name;
	m_xpos = spawnX; m_ypos = spawnY;
	m_M_speed = M_speed;
	Char_BMP = al_load_bitmap(filename.c_str());

	if(!Char_BMP)
	{
		cout << "File not found" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}

	al_convert_mask_to_alpha(Char_BMP,al_map_rgb(255,0,255)); //makes the rgb code for pink as transparent
	m_width = al_get_bitmap_width(Char_BMP); //Gets Sprite Width
	m_height = al_get_bitmap_height(Char_BMP); //Gets Sprite Height
}

int Character::getXpos(){return m_xpos;}
int Character::getYpos(){return m_ypos;}
int Character::getWidth(){return m_width;}
int Character::getHeight(){return m_height;}

void Character::setXpos(int xpos){m_xpos = xpos;};
void Character::setYpos(int ypos){m_ypos = ypos;};

void Character::left() //This will move the character to the left
{
	m_xpos = m_xpos - m_M_speed;
}

void Character::right() //This will move the character to the right
{
	m_xpos = m_xpos + m_M_speed;
}

void Character::crouchOrClimb() //This will make the character crouch or climb depending on where the character is standing
{
	/*
	Implement if condition to check if character is on climbable tile
	and if not then do crouch animation
	*/
}

void Character::Character_Draw()
{
	al_convert_mask_to_alpha(Char_BMP,al_map_rgb(255,0,255));//Makes the rgb code 255,0,255 transparent
	al_draw_bitmap(Char_BMP,m_xpos,m_ypos,0); //Draws the sprite in the xpos and ypos coordinates
}

Character::~Character()
{
	al_destroy_bitmap(Char_BMP);
}