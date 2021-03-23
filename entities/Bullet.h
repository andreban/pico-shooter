#include "pico/stdlib.h"
#include "pico_display.hpp"

#ifndef PICO_SHOOTER_BULLET_H
#define PICO_SHOOTER_BULLET_H

const uint BULLET_WIDTH = 4;
const uint BULLET_HEIGHT = 4;

class Bullet {
private:
    int velocity;
public:
    bool dead = false;
    pimoroni::Rect bounds;
    Bullet(uint x, uint y);
    ~Bullet();
    void update();
    void render(pimoroni::PicoDisplay &display);
    bool is_dead();
};

#endif //PICO_SHOOTER_BULLET_H
