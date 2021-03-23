#include "pico/stdlib.h"
#include "pico_display.hpp"

#ifndef PICO_SHOOTER_BUTTONS_H
#define PICO_SHOOTER_BUTTONS_H

class Button {
private:
    bool current_state = false;
    bool previous_state = false;
public:
    void update(bool current_state);
    bool pressed();
    bool released();
    bool state();
    void reset();
};


#endif //PICO_SHOOTER_BUTTONS_H
