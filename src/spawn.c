#include "saveManager.h"

#define RGB16(r,g,b)  ((r)+(g<<5)+(b<<10)) 
#define gameColour  (RGB16(10,5,25))


void logoScreen(unsigned short* Screen)
{
	char x,y;
	//find better way to handle text display.
}

void fillScreen(unsigned short* Screen, unsigned short Colour)
{
	char x,y;
	for(x = 0; x<240;x++)   //loop width of screen
	{
		for(y = 0; y<160; y++)  //loop height of screen
		{
			Screen[x+y*240] = Colour;
		}
	}
}

int main()
{
	char x,y;  
	unsigned short* Screen = (unsigned short*)0x6000000; 
	*(unsigned long*)0x4000000 = 0x403; // mode3, bg2 on 

	fillScreen(Screen, gameColour);

	if(readSaveData(8388607) == 255){
		Screen[150+100*240] = RGB16(5000,0,0); //debug
	}

	for(x = 20; x<=60; x+=15)
	{
		for(y = 30; y<50; y++)
    {
			Screen[x+y*240] = RGB16(31,31,31);  
    }
  }
	for (x = 20; x < 35; x++)
  {
		Screen[x+40*240] = RGB16(31,31,31);  
  }
	
	while(1){
		//handle input, and any collisions etc
	} 

}