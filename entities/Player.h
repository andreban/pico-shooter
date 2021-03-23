#include "pico_display.hpp"
#include "World.h"
#include "../Button.h"

#ifndef PICO_SHOOTER_PLAYER_H
#define PICO_SHOOTER_PLAYER_H

const uint PLAYER_X = 12;
const uint DEFAULT_PLAYER_Y = 60;
const uint PLAYER_WIDTH = 20;
const uint PLAYER_HEIGHT = 16;

class Player {
private:
    pimoroni::Rect bounds = pimoroni::Rect(PLAYER_X, DEFAULT_PLAYER_Y, PLAYER_WIDTH, PLAYER_HEIGHT);
    Button buttonY = Button();
    bool dead = false;
public:
    void update(pimoroni::PicoDisplay &display, World &world);
    void render(pimoroni::PicoDisplay &display);
    bool is_dead();
    void reset();
};
#endif //PICO_SHOOTER_PLAYER_H
