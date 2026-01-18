cmake_minimum_required(VERSION 3.13)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Pull in Pico SDK
include(pico_sdk_import.cmake)

project(blink_pico_w C CXX ASM)

# Initialise Pico SDK
pico_sdk_init()

# Add your executable
add_executable(blink
    main.c   # your blink code
)

# Link standard Pico libraries + Pico W Wi-Fi library
target_link_libraries(blink 
    pico_stdlib
    pico_cyw43_arch_none   # Required for Pico W
)

# Generate UF2/ELF output
#pico_add_extra_outputs(blink)
