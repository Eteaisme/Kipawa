#include <libtcod.hpp>

#include <SDL3/SDL.h>

#include "player.hpp"

int main() {
    auto params = TCOD_ContextParams{};
    params.tcod_version = TCOD_COMPILEDVERSION;
    params.window_title = "Kipawa";
    params.columns = 80;
    params.rows = 50;
    params.vsync = 1;
    auto context = tcod::Context(params);
    auto console = tcod::Console{80, 50};
    auto player = Player{};

    bool running = true;
    while (running) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_EVENT_QUIT) running = false;
            if (event.type == SDL_EVENT_KEY_DOWN && event.key.key == SDLK_ESCAPE) running = false;
            player.handle_event(event);
        }

        console.clear();
        player.draw(console);
        tcod::print(console, {2, 2}, "Press ESC to quit.", {{255, 255, 255}}, std::nullopt);
        context.present(console);
    }
    return 0;
}
