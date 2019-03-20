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

#define GAMEPAK_RAM  ((unsigned short*)0x0E000000)
#define maxIndex (8388607)
#define maxData (255)

int writeSaveData(int index, int data){
    if(index > maxIndex || data > maxData){
        return 1;
    }

    unsigned short *saveMemory = GAMEPAK_RAM;

    saveMemory[index] = data; //save data here. (auto makes .sav)

    return 0; //0 normal (similar to exit status)
}

int readSaveData(int index){
    if(index > maxIndex){
        return 0;
    }

    unsigned short *saveMemory = GAMEPAK_RAM;

    return saveMemory[index];
}