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

std::string Taskas3D::to_string() const{
    
    return "(" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ")";
    
}

double Taskas3D::atstumas(const Taskas3D &kitas) const {
    double dx = x - kitas.x;
    double dy = y - kitas.y;
    double dz = z - kitas.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

void Taskas3D::setTaska(double newX, double newY, double newZ) {
    x = newX; y = newY; z = newZ;
}

void Taskas3D::setX(double newX) { x = newX; }
void Taskas3D::setY(double newY) { y = newY; }
void Taskas3D::setZ(double newZ) { z = newZ; }

/* Laužtė */

Lauzte3D::Lauzte3D() : n(1) {

    taskuKoord = new Taskas3D[1];
    taskuKoord[0] = Taskas3D(0, 0, 0);

}

Lauzte3D::Lauzte3D(int n, const Taskas3D* taskai) : n(n) {
    
    taskuKoord = new Taskas3D[this->n];
    for (int i = 0; i < this->n; i++) {
        taskuKoord[i] = taskai[i];
    }

}

Lauzte3D::Lauzte3D(const Lauzte3D& other) : n(other.n) {

    taskuKoord = new Taskas3D[n];
    for (int i = 0; i < n; i++) {
        taskuKoord[i] = other.taskuKoord[i];
    }

}

Lauzte3D::~Lauzte3D() {

    delete[] taskuKoord;

}

int Lauzte3D::getN() const {
    
    return n;

}

Taskas3D Lauzte3D::getTaskas(int index) const {

    if (index < 0 || index >= n) {
        
        return Taskas3D(0, 0, 0);
    }

    return taskuKoord[index];

}

void Lauzte3D::setTaskas(int index, const Taskas3D& t) {
    
    taskuKoord[index] = t;

}

std::string Lauzte3D::to_string() const {

    std::string lauzte;
    lauzte = "Lauzte3D: [";

    for (int i = 0; i < n; i++) {
        lauzte += taskuKoord[i].to_string();
        if (i < n - 1)
            lauzte += ", ";
    }

    lauzte += "]";

    return lauzte;
}

double Lauzte3D::ilgis() const {
    double sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += taskuKoord[i].atstumas(taskuKoord[i+1]);
    }
    return sum;
}

