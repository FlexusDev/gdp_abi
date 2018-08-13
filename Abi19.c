#include "fxlib.h"
#include "stdio.h"
#include "revolution.h"

unsigned int key;

typedef char*(*sc_cpv)(void);
const unsigned int sc0135[] = { 0xD201D002, 0x422B0009, 0x80010070, 0x0135 };
#define GetVRAMAddress (*(sc_cpv)sc0135)

void draw_menu_box(unsigned int x,  unsigned int y, unsigned char str[])
{	
	
	char * vram = GetVRAMAddress();
	
	int width = 49;
	int height = 9;
	
	//Headline
	CoolText(x+2,y+2,  FONT_SIX, str, vram);
	//Upper Box Line
	DrawLine(x, y, x+width,  y, vram, 1);		
	//Lower Box Line
	DrawLine(x, y+height, x+width, y+height, vram, 1);	
	//Left Box Line
	DrawLine(x, y, x, y+height, vram, 1);	
	//Right Box Line
	DrawLine(x+width, y, x+width, y+height, vram, 1);	
	//Right Box Shadow Line
	DrawLine(x+width+1, y, x+width+1, y+height, vram, 1);	

	DrawAll(vram);

	memset(vram, 0, 0);
}	


void draw_main_menu()
{
	char * vram = GetVRAMAddress();
	

//Abitur Title
	//Headline
	CoolText(2,2,  FONT_SEVEN, "Abitur 2019 | GDP", vram  );
	//Upper Box Line
	DrawLine(0,0,127,0, vram, 1);		
	//Lower Box Line
	DrawLine(0,10,127,10, vram, 1);	
	//Left Box Line
	DrawLine(0,0,0,10, vram, 1);	
	//Right Box Line
	DrawLine(127,0,127,10, vram, 1);	

//Abitur Menu Items
	draw_menu_box(7, 14, "Mathe");
	draw_menu_box(7, 27, "Physik");
	draw_menu_box(7, 40, "Chemie");
	
	draw_menu_box(69, 14, "Informatik");
	draw_menu_box(69, 27, "Biologie");
	draw_menu_box(69, 40, "Infos ...");
	
	draw_menu_box(77, 52, "Beenden");
	
	DrawAll(vram);
}	

void draw_menu_main_select(unsigned int number)
{
	char * vram = GetVRAMAddress();
	
	int width = 47;
	int height = 8;
	
	int x = 0;
	int y = 0;
	
	switch(number){
	
		case 1: 
		x = 7;
		y = 14;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 3: 
		x = 7;
		y = 27;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 5: 
		x = 7;
		y = 40;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 2: 
		x = 69;
		y = 14;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 4: 
		x = 69;
		y = 27;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 6: 
		x = 69;
		y = 40;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
		
		case 7: 
		x = 77;
		y = 52;
		InvertArea(x+1, y+1,  x+width, y+height , vram);
		break;
	}
	
	DrawAll(vram);
}	


void draw_tab_info()
{
	char * vram = GetVRAMAddress();
	
	 Bdisp_AllClr_DDVRAM();

//Infos Title
	//Headline
	CoolText(2,2,  FONT_SEVEN, "Infos ...", vram  );
	//Upper Box Line
	DrawLine(0,0,127,0, vram, 1);		
	//Lower Box Line
	DrawLine(0,10,127,10, vram, 1);	
	//Left Box Line
	DrawLine(0,0,0,10, vram, 1);	
	//Right Box Line
	DrawLine(127,0,127,10, vram, 1);	

}	


int AddIn_main(int isAppli, unsigned short OptionNum)
{

	int menu_point = 1;

 	 Bdisp_AllClr_DDVRAM();
	
	draw_main_menu();
 	draw_menu_main_select(1);
 
  	while(1) 
	{
		GetKey(&key);
		if(KEY_CHAR_LOG == key || KEY_CTRL_EXIT == key) return 1;
		
		if(KEY_CTRL_UP == key)
		{
			if(menu_point == 7)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point - 1);
				menu_point = menu_point - 1;
			}
			else if(menu_point > 2)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point - 2);
				menu_point = menu_point - 2;
			}

		}
		
		if(KEY_CTRL_DOWN == key)
		{
			if(menu_point == 6)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point + 1);
				menu_point = menu_point + 1;
			}
			else if(menu_point < 5)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point + 2);
				menu_point = menu_point + 2;
			}
	
		}	
		
		if(KEY_CTRL_LEFT == key)
		{
			if(menu_point > 1)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point - 1);
				menu_point = menu_point - 1;
			}
		}
		
		if(KEY_CTRL_RIGHT == key)
		{
			if(menu_point  < 7)
			{
				draw_menu_main_select(menu_point);
				draw_menu_main_select(menu_point + 1);
				menu_point = menu_point + 1;
			}
		}
		
		if(KEY_CTRL_EXE == key)
		{
			if(menu_point  == 0)
			{
				 Bdisp_AllClr_DDVRAM();
				draw_main_menu();
				menu_point = 1;
				draw_menu_main_select(menu_point);
			}
			if(menu_point  == 6)
			{
				menu_point = 0;
				draw_tab_info();
			}
		}
   	}
}


#pragma section _BR_Size
unsigned long BR_Size;
#pragma section


#pragma section _TOP

int InitializeSystem(int isAppli, unsigned short OptionNum)
{
    return INIT_ADDIN_APPLICATION(isAppli, OptionNum);
}

#pragma section