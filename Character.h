#pragma once // Run once
#include <iostream>
#include <conio.h>
#include <string>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

using namespace std;
/*
	This is a container class for the basic functionality of all
	characters to be used in-game. Such as Coordinates. This
	class can be expanded when needed.
*/

class Character
{
	private:
		ALLEGRO_BITMAP* Char_BMP;
		string m_name; //Name of character
		int m_xpos, m_ypos; // Current position of character
		int m_width, m_height; // Width and height of character bitmap
	public:
		Character(string name, string filename, int spawnX , int spawnY); //constructer
		~Character(); //Destructer
		int getXpos(); int getYpos(); //returns sprite position
		void setXpos(int xpos); void setYpos(int ypos); //sets sprite position
		void left(); void right(); void jumpOrClimb(); void crouchOrClimb(); //Character Movement Controls
		int getWidth(); int getHeight(); //Gets the width and height of the character sprite
		void Character_Draw(); //Draw the character to the screen
		bool Collision_Check(Character* to_Check); //Collision Check
};