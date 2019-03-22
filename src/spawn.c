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
#include "letter.h"
#include "helloWorld.h"

typedef unsigned char      uint8;
typedef unsigned short     uint16;
typedef unsigned int       uint32;

typedef uint16 ScreenBlock[1024];
typedef uint16 Tile[32];
typedef Tile TileBlock[256];

#define VIDEOMODE_0    0x0000
#define BACKGROUND_0   0x0100

#define REG_DISPLAYCONTROL     *((volatile uint16*)(0x04000000))
#define REG_BG0_CONTROL        *((volatile uint32*)(0x04000008))

#define MEM_VRAM                ((volatile uint32*)0x6000000)
#define MEM_TILE                ((TileBlock*)0x6000000)
#define MEM_SCREENBLOCKS        ((ScreenBlock*)0x6000000)

#define MEM_BG_PALETTE          ((uint16*)(0x05000000))

int main()
{
    //load data
    memcpy(MEM_BG_PALETTE, letter, 48); //todo
    memcpy(&MEM_TILE[0][0], helloWorld, 6); //todo

    REG_BG0_CONTROL = 0x0180;// 0000 0001 1000 0000;
    REG_DISPLAYCONTROL =  VIDEOMODE_0 | BACKGROUND_0;

    while(1)
    {
    }
    return 0;
}