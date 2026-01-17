cmake_minimum_required(VERSION 3.13)
include(pico_sdk_import.cmake)

project(pico_blink C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(pico_blink
    pico_blink.c
)

target_link_libraries(pico_blink pico_stdlib)

# For Pico W onboard Wi-Fi LED
if (PICO_CYW43_SUPPORTED)
    target_link_libraries(pico_blink pico_cyw43_arch_none)
endif()

pico_add_extra_outputs(pico_blink)