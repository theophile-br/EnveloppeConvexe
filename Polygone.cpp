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