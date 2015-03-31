#include "Background.h"

Background::Background(int screen_width,int screen_height,float x,float y)
{
	m_screen_width = screen_width; m_screen_height = screen_height;
	m_background_xpos = x; m_background_ypos = y;

}

void Background::set_Background(string filename)
{
	m_background_image = al_load_bitmap(filename.c_str());

	if(!m_background_image)
	{
		cout << "Background image not found" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}
}

Background::~Background()
{
	al_destroy_bitmap(m_background_image);
}