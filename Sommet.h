//
// Created by teto on 04/01/2021.
//

#ifndef ENVELOPPE_CONVEXE_SOMMET_H
#define ENVELOPPE_CONVEXE_SOMMET_H
#include "Sommet.h"
#include "Point.h"

class Sommet {
public:
    Point coord;
    Sommet *next;
    Sommet *prev;
};


#endif //ENVELOPPE_CONVEXE_SOMMET_H
