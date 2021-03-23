#include "pico/stdlib.h"
#include "pico_display.hpp"
#include "entities/Player.h"
#include "entities/World.h"
#include <string>

extern "C" {
    int32_t add(int32_t lhs, int32_t rhs);
}

enum GameState {
    MAIN_MENU,
    GAMEPLAY,
    GAME_OVER
};

class Game {
    pimoroni::PicoDisplay display = pimoroni::PicoDisplay(
            new uint16_t[pimoroni::PicoDisplay::WIDTH * pimoroni::PicoDisplay::HEIGHT]);
    World *world = new World();
    Player *player = new Player();
    GameState gameState = GameState::MAIN_MENU;
    Button buttonA = Button();
    Button buttonB = Button();
    Button buttonX = Button();
    Button buttonY = Button();
    int32_t count = 0;
public:
    Game() {
        display.init();
        display.set_backlight(255);
    }

    void update() {
        buttonA.update(display.is_pressed(pimoroni::PicoDisplay::A));
        buttonB.update(display.is_pressed(pimoroni::PicoDisplay::B));
        buttonX.update(display.is_pressed(pimoroni::PicoDisplay::X));
        buttonY.update(display.is_pressed(pimoroni::PicoDisplay::Y));
        switch (gameState) {
            case GAMEPLAY:
                player->update(display, *world);
                world->update();
                if (player->is_dead()) {
                    gameState = GAME_OVER;
                }
                break;
            case GAME_OVER:
            case MAIN_MENU:
                if (buttonA.pressed() || buttonB.pressed() || buttonX.pressed() || buttonY.pressed()) {
                    world->reset();
                    player->reset();
                    gameState = GAMEPLAY;
                }
                break;
        }
    }

    void render() {
        switch (gameState) {
            case GAMEPLAY:
                display.set_pen(0, 0, 0);
                display.clear();
                world->render(display);
                player->render(display);
                display.set_pen(255, 255, 255);
                count = add(count, 1);
                display.text(std::to_string(count), pimoroni::Point(10, 10), 0);
                break;
            case GAME_OVER:
                display.set_pen(255, 255, 255);
                display.text("Game Over", pimoroni::Point(100, 55), 0);
                break;
            case MAIN_MENU:
                display.set_pen(0, 0, 0);
                display.clear();
                display.set_pen(255, 255, 255);
                display.text("Pico Shooter", pimoroni::Point(20, 20), 200, 4);
                break;
        }
        display.update();
    }
};

int main() {
    Game *game = new Game();
    while (true) {
        game->update();
        game->render();
    }
}
