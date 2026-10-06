#include "player.hpp"

#include <SDL3/SDL.h>

void Player::handle_event(const SDL_Event& event) {
    if (event.type != SDL_EVENT_KEY_DOWN || event.key.repeat) return;

    switch (event.key.key) {
        case SDLK_W:
            position[1] -= move_amount;
            break;
        case SDLK_A:
            position[0] -= move_amount;
            break;
        case SDLK_S:
            position[1] += move_amount;
            break;
        case SDLK_D:
            position[0] += move_amount;
            break;
        default:
            break;
    }
}

void Player::draw(tcod::Console& console) const {
    tcod::print(console, position, "@", {{255, 255, 255}}, {{0, 0, 0}});
}
