//
// Created by teto on 04/01/2021.
//

#include "Point.h"

Point::Point(int x, int y):x(x), y(y) {}
int Point::aGauche(const Point &a, const Point &b) const {
    double d = (b.x - a.x)*(y - a.y) - (x - a.x)*(b.y - a.y);
    if(d == 0){
        return 0;
    }else if(d < 0){
        return 0;
    } else if (d > 0){
        return 1;
    }
}

bool Point::operator< (const Point &other) const {
    return x < other.x;
}