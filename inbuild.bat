@echo off
REM 1. Go to build folder
mkdir build 2>nul
cd build

REM 2. Run CMake
cmake -G Ninja -DPICO_SDK_PATH=C:\Users\soume\Documents\Pico\pico-sdk ..

REM 3. Build project
ninja

REM 4. Convert ELF to UF2
C:\Users\soume\Documents\Pico\picotool\build\picotool.exe uf2 convert blink.elf blink.uf2

REM 5. Detect Pico USB drive automatically
for /f "tokens=2 delims=:" %%D in ('wmic logicaldisk where "Description='Removable Disk'" get DeviceID /value ^| find "="') do set PICO_DRIVE=%%D:

REM 6. Copy UF2 to Pico
if exist %PICO_DRIVE%\ (
    copy blink.uf2 %PICO_DRIVE%\ /Y
    echo Flashing complete!
) else (
    echo Pico not detected! Plug it in BOOTSEL mode and rerun.
)

pause
