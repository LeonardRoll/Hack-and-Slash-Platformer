#include <iostream>
#include <conio.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_font.h>
#include <allegro5/allegro_ttf.h>

using namespace std;

//Class includes
#include "Character.h"
#include "Main_Char.h"
#include "GUI.h"

//Function Declarations
int initialize_allegro();
void process_events();

//Globals
	//Keyboard Events
	enum KEYS_PRESSED_LIST 
	{
		KEY_ESCAPE, KEY_R, KEY_G, KEY_B,
		KEY_W, KEY_A,KEY_S, KEY_D, //Player Movement
		SIZE_OF_KEYS_PRESSED_ENUM //Keys that can be pressed
	};

	bool keys_pressed[SIZE_OF_KEYS_PRESSED_ENUM];

	//Allegro Display
	ALLEGRO_DISPLAY* display = NULL; // Allegro display pointer
	ALLEGRO_DISPLAY_MODE fullscreen_display; //Create a fullscreen display
	int screen_width, screen_height;
	//Event Queue
	ALLEGRO_EVENT_QUEUE* event_queue = NULL; // Creates Event Queue
	//Bitmaps
	ALLEGRO_BITMAP* Main_Char_BMP = NULL;
	//GUI
	GUI* Main_GUI = NULL;
	//Character
	Main_Char* Main_Character = NULL;
int main()
{
	//variables
	int r = 255, g = 255 , b = 255; //USed for display testing

	//Initializers
	bool init_all = initialize_allegro();

	if(init_all != 0)
	{
		return init_all; //Exit
	}

	//Program Loop
	while(!keys_pressed[KEY_ESCAPE]) // loop until escape is pressed
	{
		process_events(); //handle the events as they occur

		//Key press checks
		if(keys_pressed[KEY_R]) // If R is pressed
		{
			if(++r > 255)
				r = 0;
		}

		if(keys_pressed[KEY_G]) // If G is pressed
		{
			if(++g > 255)
				g = 0;
		}

		if(keys_pressed[KEY_B]) // if B is pressed
		{
			if(++b > 255)
				b = 0;
		}
		if(keys_pressed[KEY_D])
		{
			Main_Character->right();
		}
		if(keys_pressed[KEY_A])
		{
			Main_Character->left();
		}

		al_clear_to_color(al_map_rgb(r,g,b)); // clear display to RGB code
		
		//Bitmap Draw
		al_draw_bitmap(Main_Char_BMP,0,0,0);
		//Text Draw
		//Main_GUI->shrink_Health_Bar(1); //Used For Testing Healthbar
		Main_GUI->TEST();
		Main_GUI->GUI_Draw();
		Main_Character->Character_Draw();
		al_convert_mask_to_alpha(Main_Char_BMP, al_map_rgb(255,0,255)); // set the rgb code 255,0,255 on the bitmap to transparent

		al_flip_display(); //display what has been drawn on screen
		al_rest(0.10); // wait 0.1 seconds

	}

	//Cleanup 
	al_destroy_display(display);
	al_destroy_event_queue(event_queue);
	al_destroy_bitmap(Main_Char_BMP);
	Main_GUI->~GUI();
	
	return 0;
}

int initialize_allegro()
{
	if(!al_init()) // if allegro fails to initialize
	{
		cout << "Allegro initialize failed" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
		return -1;
	}

	//Get Monitor Information to decide screen resolution
	ALLEGRO_MONITOR_INFO Moni_Info;
	al_get_monitor_info(0, &Moni_Info);

	screen_width = Moni_Info.x2 - Moni_Info.x1;
	screen_height = Moni_Info.y2 - Moni_Info.y1;

	cout << screen_width << "x" << screen_height << endl;
	if(!al_install_keyboard()) // allegro keyboard input
	{
		cout << "Keyboard initialization failed" << endl;
		cout << "Press any key to exit" << endl;
		 _getch();
		return -1;
	}

	for(int i = 0 ; i < SIZE_OF_KEYS_PRESSED_ENUM; i++) //initialize keypress array
	{
		keys_pressed[i] = false;
	}
	
	al_get_display_mode(al_get_num_display_modes() - 1, &fullscreen_display);
	al_set_new_display_flags(ALLEGRO_FULLSCREEN);
	display = al_create_display(screen_width,screen_height); // Create a display of 800 x 600 

	if(!display) // if display fails to initialize
	{
		cout << "Display initialization failed" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
		return -1;
	}

	al_set_window_position(display, 250, 50); // position display window on screen

	event_queue = al_create_event_queue(); // Create event queue

	if(!event_queue) //if event queue fails to create
	{
		cout << "Event queue creation failed" << endl;
		cout << "Press any key to exit" << endl;
			_getch();
		return -1;
	}

	//Bitmap
	al_init_image_addon(); // initialize allegro image loader
	Main_Char_BMP = al_load_bitmap("../Assets/Bitmaps/Place_Holder.bmp");

	if(!Main_Char_BMP) // if Main Char Bitmap Failed to initialize
	{
		cout << "Bitmap Failed to initialize" << endl;
		cout << "Press any key to continue" << endl;
			_getch();
		
		//Cleanup
		al_destroy_bitmap(Main_Char_BMP);
		al_destroy_display(display);

		return -1;
	}

	//Main Character
	Main_Character = new Main_Char(0,0,"Hero","../Assets/Bitmaps/Place_Holder.bmp",10);


	Main_GUI = new GUI(screen_width,screen_height);

	if(!Main_GUI)
	{
		cout << "GUI did not initialize" << endl;
		cout << "Press any key to continue" << endl;
			_getch();
	}
	
	Main_GUI->init_font("../Assets/Font/DeJaVuSans.ttf");
	Main_GUI->set_HUD("../Assets/GUI/GUI_HUD.bmp");
	Main_GUI->set_Health_Bar("../Assets/GUI/GUI_Health_Bar.bmp",210,10);

	al_register_event_source(event_queue,al_get_display_event_source(display)); // register the display to the event queue so that changes tp the display events can be processed
	al_register_event_source(event_queue,al_get_keyboard_event_source()); // register the keyboard so that the keyboard events can be processed

	cout << "Allegro initialized" << endl;
	return 0;
}

void process_events()
{
	ALLEGRO_EVENT allegro_event;

	bool got_event = al_get_next_event(event_queue, &allegro_event);//get the next event on the queue

	if(got_event == false) //when there is no event waiting
		return;

	if(allegro_event.type == ALLEGRO_EVENT_KEY_DOWN) // Test if the key is pressed down
	{
		switch(allegro_event.keyboard.keycode)
		{
			case ALLEGRO_KEY_ESCAPE:
				keys_pressed[KEY_ESCAPE] = true;
				break;
			case ALLEGRO_KEY_R:
				keys_pressed[KEY_R] = true;
				break;
			case ALLEGRO_KEY_G:
				keys_pressed[KEY_G] = true;
				break;
			case ALLEGRO_KEY_B:
				keys_pressed[KEY_B] = true;
				break;
			case ALLEGRO_KEY_W:
				keys_pressed[KEY_W] = true;
				break;
			case ALLEGRO_KEY_A:
				keys_pressed[KEY_A] = true;
				break;
			case ALLEGRO_KEY_S:
				keys_pressed[KEY_S] = true;
				break;
			case ALLEGRO_KEY_D:
				keys_pressed[KEY_D] = true;
				break;
		}
	}

	if(allegro_event.type == ALLEGRO_EVENT_KEY_UP) // Test if the key is pressed up
	{
		switch(allegro_event.keyboard.keycode)
		{
			case ALLEGRO_KEY_ESCAPE:
				keys_pressed[KEY_ESCAPE] = false;
				break;
			case ALLEGRO_KEY_R:
				keys_pressed[KEY_R] = false;
				break;
			case ALLEGRO_KEY_G:
				keys_pressed[KEY_G] = false;
				break;
			case ALLEGRO_KEY_B:
				keys_pressed[KEY_B] = false;
				break;
			case ALLEGRO_KEY_W:
				keys_pressed[KEY_W] = false;
				break;
			case ALLEGRO_KEY_A:
				keys_pressed[KEY_A] = false;
				break;
			case ALLEGRO_KEY_S:
				keys_pressed[KEY_S] = false;
				break;
			case ALLEGRO_KEY_D:
				keys_pressed[KEY_D] = false;
				break;
		}
	}
}