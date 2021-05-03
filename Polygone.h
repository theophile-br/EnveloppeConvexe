//
// Created by teto on 04/01/2021.
//

#ifndef ENVELOPPE_CONVEXE_POLYGONE_H
#define ENVELOPPE_CONVEXE_POLYGONE_H
#include "Sommet.h"
#include "Point.h"
#include <SDL.h>
#include <vector>

class Polygone {
public:
    Polygone();
    Sommet* sommet;
    Sommet* ajouteSommet(const Point &p, Sommet *s);
    void supprimeSommet(Sommet *s);
};

void Create_Enveloppe_Convexe(std::vector<Point> &points, Polygone &P);


#endif //ENVELOPPE_CONVEXE_POLYGONE_H
