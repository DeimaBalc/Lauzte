#include "lauzte.h"
#include <iostream>

Taskas3D::Taskas3D(double x, double y, double z) : x(x), y(y), z(z) {};

double Taskas3D::getX() const {
    return x;
}

double Taskas3D::getY() const {
    return y;
}

double Taskas3D::getZ() const {
    return z;
}

