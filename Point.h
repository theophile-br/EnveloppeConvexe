//
// Created by teto on 04/01/2021.
//

#ifndef ENVELOPPE_CONVEXE_POINT_H
#define ENVELOPPE_CONVEXE_POINT_H


class Point {
public:
    int x, y;
    Point(int x, int y);
    int aGauche(const Point &a, const Point &b);
};


#endif //ENVELOPPE_CONVEXE_POINT_H
