//
// Created by andre on 27/02/2021.
//

#include "Button.h"

void Button::update(bool state) {
    this->previous_state = this->current_state;
    this->current_state = state;
}

bool Button::pressed() {
    return current_state && !previous_state;
}

bool Button::released() {
    return !current_state && previous_state;
}

bool Button::state() {
    return current_state;
}

void Button::reset() {
    previous_state = false;
    current_state = false;
}
