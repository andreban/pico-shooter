//
// Created by andre on 26/02/2021.
//

#include "World.h"

void World::spawn_bullet(uint x, uint y) {
    Bullet bullet = Bullet(x, y);
    this->bullets.push_back(bullet);
}

void World::spawn_enemy() {
    Segment last_wall_segment = walls.segments->back();
    uint range = pimoroni::PicoDisplay::HEIGHT - last_wall_segment.top_height - last_wall_segment.bottom_height -
            Enemy::HEIGHT;
    Enemy enemy = Enemy(last_wall_segment.top_height + std::rand() % range);
    this->enemies.push_back(enemy);
}

void World::update_bullets() {
    auto it = bullets.begin();
    while (it != bullets.end()) {
        it->update();
        if (it->is_dead()) {
            it = bullets.erase(it);
            continue;
        }
        bool dead = false;
        // Check if player collided with walls.
        for (int i = it->bounds.x; i < it->bounds.x + it->bounds.w; i++) {
            Segment segment = walls.segments->at(i);
            if (it->bounds.y <= segment.top_height ||
                    it->bounds.y + it->bounds.h >= pimoroni::PicoDisplay::HEIGHT - segment.bottom_height) {
                it = bullets.erase(it);
                dead = true;
                break;
            }
        }

        if (!dead) {
            it++;
        }
    }
}

void World::update_enemies() {
    auto it = enemies.begin();
    while (it != enemies.end()) {
        it->update();
        if (it->is_dead()) {
            it = enemies.erase(it);
            continue;
        }

        bool killed = false;
        auto bullet_it = bullets.begin();
        while (bullet_it != bullets.end()) {
            if (it->bounds.intersects(bullet_it->bounds)) {
                it->dead = true;
                bullet_it->dead = true;
                it = enemies.erase(it);
                bullets.erase(bullet_it);
                killed = true;
                break;
            }
            bullet_it++;
        }
        if (!killed) {
            it++;
        }
    }
}

void World::update() {
    int rand = std::rand();
    if (rand % 60 == 0) {
        spawn_enemy();
    }
    update_bullets();
    update_enemies();
    walls.update();
}

void World::render(pimoroni::PicoDisplay &display) {
    walls.render(display);
    for (auto bullet : bullets) {
        bullet.render(display);
    }

    for (auto enemy : enemies) {
        enemy.render(display);
    }
}

void World::reset() {
    bullets.clear();
    enemies.clear();
    walls.reset();
}
