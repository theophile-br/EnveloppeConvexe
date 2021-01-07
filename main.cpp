#include <iostream>
#include "Polygone.h"
#include <SDL.h>

using namespace std;

void eventLoop();

int main() {
    // SDL_INIT
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
        return 1;
    }
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;

    if (SDL_CreateWindowAndRenderer(640, 480, 0, &window, &renderer) != 0) {
        return 0;
    }

    // POLYGONE_CREATE
    Polygone polygone = Polygone();
    Sommet *currentSommet = polygone.ajouteSommet({10, 10}, nullptr);
    currentSommet = polygone.ajouteSommet({150, 150}, currentSommet);
    polygone.ajouteSommet({10, 150}, currentSommet);

    // POLYGONE_DRAW
    SDL_SetRenderDrawColor(renderer, 88, 61, 114, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    polygone.trace(renderer);

    // EVENT_LOOP
    eventLoop();

    return 0;
}

/**
 * Handle UI Windows
 */
void eventLoop(){
    int close = 0;
    while (!close) {
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    close = 1;
                    break;
                case SDL_KEYDOWN:
                    close = 1;
                    switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            close = 1;
                            break;
                    };
                    break;
            };
        };
    };
}