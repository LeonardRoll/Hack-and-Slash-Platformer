#pragma once //Run only once

/*Includes*/
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
	This is a file reader so that reads the string of the file.
	This will be used to read different text lines to be used by the game
	such as Levels,Assets,Power Ups etc.
*/

class Text_File_Reader
{
	private:
		fstream textFile; //Text file to read or write
		string line;
	public:
		Text_File_Reader();//Constructor
		string read_text(string filename,int line);//function that will read and return specific lines
};