@echo off

echo --- Cleaning tmp ---
rm main.o
rm main.elf
rm main.gba
rm dist/main.gba
echo --- Building ROM ---
arm-none-eabi-gcc -c src/main.c -mthumb-interwork -mthumb -O2 -o main.o
arm-none-eabi-gcc main.o -mthumb-interwork -mthumb -specs=gba.specs -o main.elf
arm-none-eabi-objcopy -v -O binary main.elf main.gba
rm main.o
rm main.elf
mkdir dist
MOVE main.gba dist/
echo --------------------

echo Started VisualBoyAdvance

"C:\Users\Jack\Desktop\GameBoy Development\GBA Emulator (VBA)\VisualBoyAdvance.exe" dist/main.gba
 
echo VisualBoyAdvance Closed