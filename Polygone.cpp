//
// Created by teto on 04/01/2021.
//

#include "Polygone.h"
#include "Sommet.h"

Polygone::Polygone(): sommet(nullptr) {}

Sommet* Polygone::ajouteSommet(const Point &p, Sommet *s) {
    Sommet *nvxSommet = new Sommet{{ p.x, p.y}, nullptr, nullptr};
    if(s == nullptr){
        nvxSommet->next = nvxSommet;
        nvxSommet->prev = nvxSommet;
        sommet = nvxSommet;
    } else {
        nvxSommet->prev = s->prev;
        nvxSommet->prev->next = nvxSommet;
        nvxSommet->next = s;
        s->prev = nvxSommet;
    }
    return nvxSommet;
}

void Polygone::supprimeSommet(Sommet *s) {
    s->next->prev = s->prev;
    s->prev->next = s->next;
    delete s;
}

void enveloppe(std::vector<Point> &points, Polygone &P) {
    Sommet* currentSommet = nullptr;
    int numberOfPoints = points.size();

    // SORTING POINTS BY X INCREASE
    std::sort(points.begin(), points.end(),[](Point a, Point b) {
        return a.x < b.x;
    });

    // ADD FIRST 3 POINTS To FORM A TRIANGLE
    currentSommet = P.ajouteSommet(points[0],currentSommet);
    currentSommet = P.ajouteSommet(points[1],currentSommet);
    currentSommet = P.ajouteSommet(points[2],currentSommet);

    // ADD THE OTHER POINT
    for(int i = 3; i < numberOfPoints; i++) {
        Sommet* beginSommet = currentSommet;
        Sommet* endSommet = currentSommet;

        while(!points[i].aGauche(beginSommet->coord,beginSommet->next->coord)) {
            beginSommet = beginSommet->next;
        }

        while(!points[i].aGauche(endSommet->prev->coord,endSommet->coord)) {
            endSommet = endSommet->prev;
        }

        while (beginSommet->prev != endSommet) {
            P.supprimeSommet(endSommet->next);
        }

        currentSommet = P.ajouteSommet(points[i],beginSommet);

    }
}