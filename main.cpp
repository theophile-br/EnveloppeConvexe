#include <iostream>
#include "Polygone.h"
#include "Point.h"
#include <SDL.h>
#include <vector>

using namespace std;

void eventLoop();
void trace(const Polygone &p, SDL_Renderer *renderer);
void trace(const vector<Point> &points, SDL_Renderer *renderer);
void segment(const Point &a, const Point &b, SDL_Renderer *renderer);
void enveloppe(const vector<Point> &points, Polygone &P);

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

    // INIT POINT
    vector<Point> points = {
            {10, 50},
            {35, 110},
            {43, 70},
            {100, 130},
            {120, 10},
            {123, 95},
            {135, 50},
            {145, 80},
            {200, 75},
    };

    // POLYGONE_CREATE
    Polygone polygone = Polygone();
    enveloppe(points,polygone);

    // POLYGONE_DRAW
    SDL_SetRenderDrawColor(renderer, 88, 61, 114, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(renderer);
    trace(polygone, renderer);

    // DRAW POINTS
    trace(points,renderer);

    // RENDER
    SDL_RenderPresent(renderer);

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
                    /*switch (event.key.keysym.scancode) {
                        case SDL_SCANCODE_ESCAPE:
                            close = 1;
                            break;
                    };*/
                    break;
            };
        };
    };
}
/**
 * Trace des points
 * @param point
 * @param renderer
 */
void trace(const vector<Point> &points, SDL_Renderer *renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, SDL_ALPHA_OPAQUE);
    for(const Point &point : points) {
        int size = 4;
        const SDL_Rect rect = {
                point.x - size,point.y - size,size*2,size*2
        };
        SDL_RenderDrawRect(renderer,&rect);
        SDL_RenderFillRect(renderer,&rect);
    }
}


/**
 * Trace tout les segments d'un Polygone
 * @param p Un polygone
 */
void trace(const Polygone &p, SDL_Renderer* renderer) {
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    Sommet *currentSommet = p.premier;

    do{
        segment(currentSommet->coord, currentSommet->next->coord, renderer);
        currentSommet = currentSommet->next;
    }while(currentSommet != p.premier);
}

/**
 * Trace un segment
 * @param a point A
 * @param b point B
 */
void segment(const Point &a, const Point &b, SDL_Renderer* renderer) {
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
}

void enveloppe(const vector<Point> &points, Polygone &P) {
    Sommet* currentSommet = nullptr;
    int numberOfPoints = points.size();
    for(int i = 0; i < numberOfPoints; i++) {
        if( i < 3) {
            currentSommet = P.ajouteSommet(points[i],currentSommet);
        } else {
            Sommet* beginSommet = currentSommet;
            Sommet* endSommet = currentSommet;
            while(points[i].aGauche(beginSommet->coord,beginSommet->prev->coord)) {
                beginSommet = beginSommet->prev;
            }

            while(points[i].aGauche(endSommet->coord,endSommet->prev->coord)) {
                endSommet = endSommet->next;
            }

            if(beginSommet != endSommet) {
                P.supprimeSommet(beginSommet->next);
                P.supprimeSommet(endSommet->prev);
            } else {
                P.supprimeSommet(beginSommet->next);
            }
            currentSommet = P.ajouteSommet(points[i],beginSommet);
        }
    }
}