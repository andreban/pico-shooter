#include "pico/stdlib.h"
#include "Bullet.h"
#include "Walls.h"
#include "Enemy.h"

#ifndef PICO_SHOOTER_WORLD_H
#define PICO_SHOOTER_WORLD_H

class World {
private:
    void update_enemies();
    void update_bullets();
public:
    std::vector<Bullet> bullets;
    std::vector<Enemy> enemies;
    Walls walls = Walls();
    void spawn_bullet(uint x, uint y);
    void spawn_enemy();
    void update();
    void render(pimoroni::PicoDisplay &picoDisplay);
    void reset();
};


#endif //PICO_SHOOTER_WORLD_H
