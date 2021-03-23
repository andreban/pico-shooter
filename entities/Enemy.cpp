//
// Created by andre on 27/02/2021.
//

#include "Enemy.h"
#include "World.h"

Enemy::Enemy(int32_t y) {
    bounds = pimoroni::Rect(240, y, WIDTH, HEIGHT);
    velocity = -((std::rand() % 3) + 1);
    dead = false;
}

Enemy::~Enemy() {

}

void Enemy::update() {
    bounds.x += velocity;
    if (bounds.x + bounds.w <= 0) {
        dead = true;
    }
}

void Enemy::render(pimoroni::PicoDisplay &display) {
    display.set_pen(0, 255, 0);
    display.rectangle(bounds);
}

bool Enemy::is_dead() {
    return dead;
}