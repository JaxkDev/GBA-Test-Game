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

#include <string.h>
#include "logo.h"

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;

typedef uint32 Tile[16];
typedef Tile TileBlock[256];

#define VIDEOMODE_0    0x0000
#define ENABLE_OBJECTS 0x1000
#define MAPPINGMODE_1D 0x0040

#define REG_DISPLAYCONTROL     *((volatile uint16*)(0x04000000))

#define MEM_VRAM        ((volatile uint32*)0x6000000)
#define MEM_TILE		((TileBlock*)0x6000000 )
#define MEM_PALETTE   ((uint16*)(0x05000200))
#define SCREEN_W    	240
#define SCREEN_H         160

typedef struct ObjectAttributes {
	uint16 attr0;
	uint16 attr1;
	uint16 attr2;
	uint16 pad;
} __attribute__((packed, aligned(4))) ObjectAttributes;

#define MEM_OAM            ((volatile ObjectAttributes *)0x07000000)

#define REG_VCOUNT_ADDR 0x04000006
#define REG_VCOUNT      (* (volatile uint16*) REG_VCOUNT_ADDR)

inline void vsync()
{
  while (REG_VCOUNT >= 160);
  while (REG_VCOUNT < 160);
}


int main() {
	
	// setup tile //

	memcpy(MEM_PALETTE, logoPal,  logoPalLen );
    memcpy(&MEM_TILE[4][1], logoTiles, logoTilesLen);

    volatile ObjectAttributes *logoAttribs = &MEM_OAM[0];

    logoAttribs->attr0 = 0x2032; // 8bpp tiles, SQUARE shape, at y coord 50
    logoAttribs->attr1 = 0x4064; // 16x16 size when using the SQUARE shape
    logoAttribs->attr2 = 2;      // Start at the first tile in tile

	REG_DISPLAYCONTROL =  VIDEOMODE_0 | ENABLE_OBJECTS | MAPPINGMODE_1D;//0x1000 | 0x0040;

	//////////////////////////////
	
	while(1){}

	return 0;
}
