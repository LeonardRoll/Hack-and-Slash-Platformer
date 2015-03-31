#pragma once //Run only once

/*Includes*/
#include <iostream>
#include <fstream>
using namespace std;

/*
	This is a file reader so that reads the string of the file.
	This will be used to read different text lines to be used by the game
	such as Levels,Assets,Power Ups etc.
*/

class Text_File_Reader
{
	Text_File_Reader init_Reader();//Constructor
	string read_text(string filename);//function that will read 
};