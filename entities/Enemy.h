#include "pico/stdlib.h"
#include "pico_display.hpp"

#ifndef PICO_SHOOTER_ENEMY_H
#define PICO_SHOOTER_ENEMY_H

class Enemy {
private:
    int velocity = -1;

public:
    bool dead;
    static const uint WIDTH = 10;
    static const uint HEIGHT = 10;
    pimoroni::Rect bounds;
    Enemy(int32_t y);
    ~Enemy();
    bool is_dead();
    void update();
    void render(pimoroni::PicoDisplay &display);
};

#endif //PICO_SHOOTER_ENEMY_H
