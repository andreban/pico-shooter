//
// Created by andre on 27/02/2021.
//

#include "Walls.h"

Walls::Walls() {
    reset();
};

void Walls::update() {
    segments->erase(segments->cbegin());
    Segment last = segments->back();
    int rand_top = std::rand() % 3;
    int rand_bottom = std::rand() % 3;
    int new_top_height = std::min(std::max((int)last.top_height + rand_top - 1, 0), MAX_WALL_HEIGHT);
    int new_bottom_height = std::min(std::max((int)last.bottom_height + rand_bottom - 1, 0), MAX_WALL_HEIGHT);
    segments->push_back(Segment(new_top_height, new_bottom_height));
}

void Walls::render(pimoroni::PicoDisplay &display) {
    display.set_pen(255, 0, 0);
    for (int i = 0; i < pimoroni::PicoDisplay::WIDTH; i++) {
        Segment segment = segments->at(i);
        display.line(pimoroni::Point(i, 0), pimoroni::Point(i, segment.top_height));
        display.line(pimoroni::Point(i, pimoroni::PicoDisplay::HEIGHT - segment.bottom_height),
                      pimoroni::Point(i, pimoroni::PicoDisplay::HEIGHT));
    }
}
void Walls::reset() {
    segments->clear();
    for (int i = 0; i < pimoroni::PicoDisplay::WIDTH; i++) {
        segments->push_back(Segment(INITIAL_WALL_HEIGHT, INITIAL_WALL_HEIGHT));
    }
}
