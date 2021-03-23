cmake_minimum_required(VERSION 3.17)

include(pico_sdk_import.cmake)
set(ENV{PICO_SDK_PATH} D:/Projects/pico/pico-sdk/)
set(PIMORONI_SDK D:/Projects/pico/pimoroni-pico/)
include(pimoroni_pico_display_import.cmake)

project(pico_shooter C CXX ASM)

set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Initialize the SDK
pico_sdk_init()

add_executable(pico_shooter main.cpp entities/Player.cpp entities/Player.h entities/World.cpp entities/World.h entities/Bullet.cpp entities/Bullet.h entities/Enemy.cpp entities/Enemy.h Button.cpp Button.h entities/Walls.cpp entities/Walls.h)

# Pull in our pico_stdlib which aggregates commonly used features
target_link_libraries(pico_shooter pico_stdlib pico_display hardware_spi hardware_pwm
        "D:\\Projects\\rust-hello-lib\\target\\thumbv6m-none-eabi\\debug\\libadd.a")

# create map/bin/hex/uf2 file etc.
pico_add_extra_outputs(pico_shooter)
