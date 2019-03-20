@echo off

echo --- Cleaning tmp ---
rm game.o
rm game.elf
rm game.gba
rm dist/game.gba
echo --- Building ROM ---
arm-none-eabi-gcc -c src/spawn.c -mthumb-interwork -mthumb -O2 -o spawn.o
arm-none-eabi-gcc -c src/saveManager.c -mthumb-interwork -mthumb -O2 -o saveManager.o
arm-none-eabi-gcc saveManager.o spawn.o -mthumb-interwork -mthumb -specs=gba.specs -o game.elf
arm-none-eabi-objcopy -v -O binary game.elf game.gba
rm game.o
rm game.elf
mkdir dist
MOVE game.gba dist/
echo --------------------

echo Started VisualBoyAdvance

"C:\Users\Jack\Desktop\GameBoy Development\GBA Emulator (VBA)\VisualBoyAdvance.exe" dist/game.gba
 
echo VisualBoyAdvance Closed