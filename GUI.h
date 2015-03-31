#pragma once // Run once
#include <iostream>
#include <conio.h>
#include <string>
#include <sstream>
#include <allegro5\allegro.h>
#include <allegro5\allegro_image.h>
#include <allegro5\allegro_font.h>
#include <allegro5\allegro_ttf.h>

using namespace std;
/*
	This class contains the main game GUI which will
	inform the player about his health amount of lives left
	and other such information using a series of images and 
	text.
*/

class GUI
{
	private:
		ALLEGRO_BITMAP* GUI_HUD; //Heads up display to be under healthbar
		ALLEGRO_BITMAP* Health_Bar; //The Healthbar of the character
		ALLEGRO_BITMAP* Lives_Left; //THe image to be used to indicate how many lives are left
		ALLEGRO_FONT* GUI_font; //Font of the GUI
		ALLEGRO_FONT* GUI_Game_Over_font;//Font for Game Over Text
		double m_screen_width, m_screen_height; //Used to calculate the positions of the GUI
		double Health_Bar_Height, Health_Bar_Width; // width and height of Health Bar
		double Lives_Left_Height, Lives_Left_Width; // width and height of Lives Left
		double Health_Bar_xpos, Health_Bar_ypos; //Position of the Healthbar
		double Lives_Left_xpos, Lives_Left_ypos; //Position of Lives Left icon
		double Health_Bar_Scale; //scale of the health bar

	public:
		GUI(int screen_width,int screen_height); // Constructor
		~GUI(); //Destructor
		void init_font(string filename); //set up the font of the GUI from the filename
		void set_HUD(string filename);
		void set_Health_Bar(string filename,int xpos,int ypos); //set up the image for the health bar based on the filename
		void set_Lives_Left(string filename); //set up the image for the lives left based on the filename
		void shrink_Health_Bar(double damage); // Shrinks Health Bar based on the amount of damage taken
		void GUI_Draw(); //Function to draw GUI

		//to delete
		void TEST(); //Just to test if GUI works
};