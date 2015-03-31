#pragma once // Run once

/*Includes*/
#include <iostream>
#include <conio.h>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>

using namespace std;
/*
	This class will hold the code for the background image
	of the game which will preferably be changed per level.
	The background should also be able to have parallax movement 
	to give the illusion of depth to the level the player is 
	currently playing
*/

class Background
{
	private:
		ALLEGRO_BITMAP* m_background_image; //background image
		float m_background_xpos, m_background_ypos; //position on the x and y axis
		float m_background_xvel, m_background_yvel; //x and y velocity of background
		int m_background_xdir, m_background_ydir; //x and y direction of background
		int m_background_width, m_background_height; //Width and Height of the background image
		int m_screen_width, m_screen_height; //Used for scaling purposes
	public:
		Background(int screen_width,int screen_height,float x,float y);//Constructor
		~Background();//Destructor
		void set_Background(string filename);//fetch the bitmap for the background
};