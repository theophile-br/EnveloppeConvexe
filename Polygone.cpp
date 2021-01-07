//
// Created by teto on 04/01/2021.
//

#include "Polygone.h"
#include "Sommet.h"
#include <iostream>

Polygone::Polygone(): premier(nullptr) {}

Sommet* Polygone::ajouteSommet(const Point &p, Sommet *s) {
    Sommet *nvxSommet = new Sommet{{ p.x, p.y}, nullptr, nullptr};
    if(s == nullptr){
        nvxSommet->next = nvxSommet;
        nvxSommet->prev = nvxSommet;
        premier = nvxSommet;
    } else {
        nvxSommet->next = s->next;
        nvxSommet->prev = s;
        s->next = nvxSommet;
    }
    return nvxSommet;
}

void Polygone::supprimeSommet(Sommet *s) {
    s->prev->next = s->next;
    s->next->prev = s->prev;
    delete s;
}

/**
 * Trace un segment
 * @param a point A
 * @param b point B
 * @param renderer SDL Renderer
 */
void Polygone::segment(const Point &a, const Point &b, SDL_Renderer* renderer){
    SDL_RenderDrawLine(renderer, a.x, a.y, b.x, b.y);
}

/**
 * Trace tout les segments d'un Polygone
 * @param renderer SDL Renderer
 */
void Polygone::trace(SDL_Renderer* renderer){

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, SDL_ALPHA_OPAQUE);
    Sommet *currentSommet = premier;

    do{
        segment(currentSommet->coord, currentSommet->next->coord, renderer);
        currentSommet = currentSommet->next;
    }while(currentSommet != premier);

    SDL_RenderPresent(renderer);
}