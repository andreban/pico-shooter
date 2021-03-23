#include "Bullet.h"
#include "Walls.h"
#include "World.h"

Bullet::Bullet(uint x, uint y)  {
    bounds = pimoroni::Rect(x, y, BULLET_WIDTH, BULLET_HEIGHT);
    velocity = 1;
}

Bullet::~Bullet() {
}

bool Bullet::is_dead() {
    return dead;
}

void Bullet::update() {
    if (bounds.x + bounds.w < pimoroni::PicoDisplay::WIDTH) {
        bounds.x += velocity;
    } else {
        dead = true;
    }
}

void Bullet::render(pimoroni::PicoDisplay &display) {
    display.set_pen(255, 255, 255);
    display.rectangle(bounds);
}
