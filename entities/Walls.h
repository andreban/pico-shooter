#include "pico/stdlib.h"
#include "pico_display.hpp"

#ifndef PICO_SHOOTER_WALLS_H
#define PICO_SHOOTER_WALLS_H

const int MAX_WALL_HEIGHT = 50;
const uint INITIAL_WALL_HEIGHT = 20;

class Segment {
public:
    uint top_height;
    uint bottom_height;
    Segment(uint top_height, uint bottom_height) {
        this->top_height = top_height;
        this->bottom_height = bottom_height;
    }
};

class Walls {
public:
    std::vector<Segment> segments[135];
    Walls();
    void render(pimoroni::PicoDisplay &display);
    void update();
    void reset();
};

#endif //PICO_SHOOTER_WALLS_H
