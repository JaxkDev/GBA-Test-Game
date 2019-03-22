@echo off

echo --- Cleaning old env ---
rm -rf build
rm Game.gba
rm Game.elf
echo --- Running Make ---
make
echo --------------------

echo Started VisualBoyAdvance

"C:\Users\Jack\Desktop\GameBoy Development\GBA Emulator (VBA)\VisualBoyAdvance.exe" Game.gba
 
echo VisualBoyAdvance Closed