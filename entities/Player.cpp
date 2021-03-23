//
// Created by andre on 26/02/2021.
//

#include "Player.h"

void Player::render(pimoroni::PicoDisplay &display) {
    display.set_pen(255, 255, 255);
    display.rectangle(this->bounds);
}

void Player::update(pimoroni::PicoDisplay &display, World &world) {
    // Button A moves up and button B moves down.
    if (display.is_pressed(pimoroni::PicoDisplay::A)) {
        // Only move if not hitting ceiling.
        if (this->bounds.y > 0) {
            this->bounds.y -= 1;
        }
    } else if (display.is_pressed(pimoroni::PicoDisplay::B)) {
        // Only move if not hitting floor.
        if (this->bounds.y + this->bounds.h < pimoroni::PicoDisplay::HEIGHT - 1) {
            this->bounds.y += 1;
        }
    }

    // Check if player collided with walls.
    for (int i = bounds.x; i < bounds.x + bounds.w; i++) {
        Segment segment = world.walls.segments->at(i);
        if (bounds.y <= segment.top_height ||
            bounds.y + bounds.h >= pimoroni::PicoDisplay::HEIGHT - segment.bottom_height) {
            dead = true;
            return;
        }
    }

    // Check if player collided with enemy.
    for (const auto& enemy: world.enemies) {
        if (enemy.bounds.intersects(bounds)) {
            dead = true;
            return;
        }
    }

    // We're still alive!! Shoot!
    buttonY.update(display.is_pressed(pimoroni::PicoDisplay::Y));
    if (buttonY.pressed()) {
        world.spawn_bullet(this->bounds.x + this ->bounds.w + 1, this ->bounds.y + PLAYER_HEIGHT / 2);
    }
}

bool Player::is_dead() {
    return dead;
}

void Player::reset() {
    dead = false;
    bounds.y = DEFAULT_PLAYER_Y;
}