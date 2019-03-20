/*
MIT License

Copyright (c) 2019 Jack Honour

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

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