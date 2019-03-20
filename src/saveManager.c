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