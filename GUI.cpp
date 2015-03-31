#include "GUI.h"

GUI::GUI(int screen_width, int screen_height)
{
	Health_Bar_Scale = 1; // Ensures that the health bar is 100% scale
	m_screen_width = screen_width;
	m_screen_height = screen_height;

	//Fonts
	al_init_font_addon(); //Initialize font addon
	al_init_ttf_addon(); //Initialize true type font addon
}

void GUI::init_font(string filename)
{
	//standard_font = al_load_ttf_font("../Assets/Font/DeJaVuSans.ttf", 60 , 0);
	GUI_font = al_load_ttf_font(filename.c_str(), 10 , 0);

	if(!GUI_font)
	{
		cout << "Font failed to initialize" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}

	GUI_Game_Over_font = al_load_ttf_font(filename.c_str(),76,0);

	if(!GUI_Game_Over_font)
	{
		cout << "Game Over font failed to initialize" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}
}

void GUI::set_HUD(string filename)
{
	GUI_HUD = al_load_bitmap(filename.c_str());
	if(!GUI_HUD)
	{
		cout << "GUI HUD File not found" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}

	al_convert_mask_to_alpha(GUI_HUD,al_map_rgb(255,0,255)); //transparent mask on pink.
}

void GUI::set_Health_Bar(string filename,int xpos,int ypos)
{
	Health_Bar_xpos = xpos * (m_screen_width / 1920); // Scale with screen resolution
	Health_Bar_ypos = ypos * (m_screen_height / 1080); // Scale with screen resolution
	Health_Bar = al_load_bitmap(filename.c_str());
	if(!Health_Bar)
	{
		cout << "Health Bar File not found" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}

	al_convert_mask_to_alpha(Health_Bar,al_map_rgb(255,0,255)); //Transparent mask on pink
	Health_Bar_Height = al_get_bitmap_height(Health_Bar);//Gets height of the health bar bitmap
	Health_Bar_Width = al_get_bitmap_width(Health_Bar);//Gets width of the health bar bitmap
}

void GUI::set_Lives_Left(string filename)
{
	Lives_Left = al_load_bitmap(filename.c_str());
	if(!Lives_Left)
	{
		cout << "Lives Left File not found" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
	}

	al_convert_mask_to_alpha(Lives_Left,al_map_rgb(255,0,255)); //Transparent mask on pink
	Lives_Left_Height = al_get_bitmap_height(Lives_Left); //Gets height of lives left bitmap
	Lives_Left_Width = al_get_bitmap_width(Lives_Left);//Gets width of lives left bitmap
}

void GUI::shrink_Health_Bar(double damage)
{
	if(Health_Bar_Scale > 0) //Prevents Bitmap inversion
	{
		Health_Bar_Scale = Health_Bar_Scale - (damage / 100); //scale factor to shrink the healthbar based on the damage taken
	}
	else
		return;
}

void GUI::GUI_Draw()
{
	//HUD
	al_draw_scaled_bitmap(GUI_HUD,0,0,al_get_bitmap_width(GUI_HUD),al_get_bitmap_height(GUI_HUD),0,0,
		al_get_bitmap_width(GUI_HUD) * (m_screen_width / 1920),al_get_bitmap_height(GUI_HUD) * (m_screen_height / 1080),0); //Bitmap was intended for a 1920*1080 screen and so therefore is scaled for the current screen width and height
	//Health Bar
	al_draw_scaled_bitmap(Health_Bar,0,0,Health_Bar_Width,Health_Bar_Height,Health_Bar_xpos,Health_Bar_ypos,
		(Health_Bar_Width * (m_screen_width / 1920)) * Health_Bar_Scale,Health_Bar_Height * (m_screen_height / 1080),0);
	al_draw_textf(GUI_font, al_map_rgb(255,255,255),Health_Bar_xpos + (Health_Bar_xpos/2),Health_Bar_ypos + (Health_Bar_ypos/2),0, "%0.0f/100",Health_Bar_Scale * 100); //Text form of the percentage of health remaining
}

void GUI::TEST()
{
	if(Health_Bar_Scale <= 0)
		al_draw_textf(GUI_Game_Over_font, al_map_rgb(255,0,0), (m_screen_width/2),(m_screen_height/2),ALLEGRO_ALIGN_CENTRE,"Game Over");
}

GUI::~GUI()
{
	//Make sure you cleanup everybitmap in this class.
	al_destroy_bitmap(GUI_HUD);
	al_destroy_bitmap(Health_Bar);
	//al_destroy_bitmap(Lives_Left);
}