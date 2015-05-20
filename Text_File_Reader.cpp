#include "Text_File_Reader.h"


Text_File_Reader::Text_File_Reader(){}//Empty Constructor

string Text_File_Reader::read_text(string filename, int Line)
{
	textFile.open(filename);
	if(textFile.is_open()) //check if file is still open
	{
		int Linecount = 0;
		while( getline(textFile,line) )
		{
			if(Linecount == Line)
			{
				return line;
			}
			Linecount++;
		}

		textFile.close();
	}

	else
	{
		//Error Message Here
	}
}