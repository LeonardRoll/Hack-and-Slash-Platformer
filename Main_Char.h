#pragma once //Run only once
#include "Character.h" 

/*
	Does not require anymore includes as it already includes its 
	parent class and so therefore will gain all the includes the parent
	already has
*/

class Main_Char : public Character //Inheritance, child of character class
{
	private:
		int m_Health; // Health of the main character
		int m_Lives; // amount of lives the character still has
		int m_Score; // score the hero has whilst going through the game
		double m_M_speed; //Main Characters Movement Speed
	public:
		Main_Char(int xpos,int ypos,string name,string filename,double M_speed,int lives); //Constructor
		~Main_Char();//Destructor
		void debug(); //for debug purposes
		void reduce_Life(); void increase_Life(); //increment or decrement life
		int get_Life(); // returns Life of player
		void damage_Health(int damage);//damage the player
		bool check_Death();//checks if the player is dead
		void add_Score(int amount); void reduce_Score(int amount); //Increase or decrease score
		int get_Score();//Returns the players score
		void set_Speed(double M_speed);//Modify the default movement speed
		double get_Speed();//Returns the main characters movement speed
		void draw_Hero(); //Display the hero on the screen
};