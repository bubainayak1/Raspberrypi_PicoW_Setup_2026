Pico W Blink Project
=====================

This repository contains a simple standalone blink project for the Raspberry Pi Pico W, built using the Pico SDK v1.5.1.
It demonstrates how to set up the SDK, configure the build system, and flash firmware to the board.

-------------------------------------------------------------------------------

Project Structure
-----------------
pico-examples/
└── pico_blink_soumen/
├── build/                  # Generated build artifacts (ignored in .gitignore)
├── CMakeLists.txt           # Project build configuration
├── pico_blink.c            # Application source code
└── pico_sdk_import.cmake   # SDK import helper

-------------------------------------------------------------------------------

Prerequisites
-------------
1. Install Pico SDK
   - Clone the SDK into your workspace:
     git clone https://github.com/raspberrypi/pico-sdk --branch 1.5.1
     cd pico-sdk
     git submodule update --init
   - Place the pico-sdk folder alongside your project.

   - Source: Thanks to Nikhil Dabas
     https://github.com/ndabas/pico-setup-windows
     https://github.com/raspberrypi/pico-setup-windows

   - Note: The pico-setup-windows installer will be deprecated.
     Use the official VS Code extension instead:
     https://marketplace.visualstudio.com/items?itemName=raspberry-pi.raspberry-pi-pico

   Or   here i followed install directly:
     https://github.com/raspberrypi/pico-setup-windows/releases/latest/download/pico-setup-windows-x64-standalone.exe

2. Install FreeRTOS (optional)
   git clone https://github.com/FreeRTOS/FreeRTOS-Kernel.git

3. Install Toolchain
   - ARM GCC (10.3 or 15.2 recommended)
   - CMake
   - Ninja
   - Visual Studio Code with CMake Tools extension

-------------------------------------------------------------------------------

First-Time Setup in VS Code
---------------------------
1. Open the root Pico SDK folder (Pico-v1.5.1) in VS Code.
2. On the left side, select the CMake build option.
3. Configure the SDK path in pico_sdk_import.cmake if needed.
4. Trigger the first build to ensure the SDK is initialized.

-------------------------------------------------------------------------------

Building the Blink Project
--------------------------
Navigate to your project folder:
  cd C:\Users\soume\Documents\Pico-v1.5.1\pico-examples\pico_blink_soumen

Create build directory and compile:
  mkdir build
  cd build
  cmake .. -G Ninja -DPICO_BOARD=pico_w
  cmake --build .

This will generate a .uf2 firmware file inside the build/ directory.

-------------------------------------------------------------------------------

Flashing to Pico W
------------------
1. Connect your Pico W via USB while holding the BOOTSEL button.
2. A new USB drive will appear on your computer.
3. Copy the generated .uf2 file from the build/ folder onto the Pico drive.
4. The board will reboot automatically and start blinking the onboard LED.

-------------------------------------------------------------------------------

Demo
----
- Onboard Wi‑Fi LED blinks ON/OFF.
- External LEDs on GP2 and GP3 alternate every 100 ms.
- Serial output prints 'Hello, world!' continuously at 115200 baud.

-------------------------------------------------------------------------------

Next Steps
----------
- Extend this project with FreeRTOS tasks for multitasking.
- Add a GitHub Actions workflow (.github/workflows/build.yml) to build automatically in CI/CD.
- Explore other examples in pico-examples for networking, GPIO, and peripherals.
