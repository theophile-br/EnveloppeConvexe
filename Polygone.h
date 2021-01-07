//
// Created by teto on 04/01/2021.
//

#ifndef ENVELOPPE_CONVEXE_POLYGONE_H
#define ENVELOPPE_CONVEXE_POLYGONE_H
#include "Sommet.h"
#include "Point.h"
#include <SDL.h>

class Polygone {
public:
    Polygone();
    Sommet* premier;
    Sommet* ajouteSommet(const Point &p, Sommet *s);
    void supprimeSommet(Sommet *s);
};

#endif //ENVELOPPE_CONVEXE_POLYGONE_H
