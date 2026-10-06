#pragma once

#include <array>

#include <libtcod.hpp>

struct Player {
    std::array<int, 2> position{40, 25};
    int move_amount = 1;

    void handle_event(const SDL_Event& event);
    void draw(tcod::Console& console) const;
};
