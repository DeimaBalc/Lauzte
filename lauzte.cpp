#include "lauzte.h"
#include <iostream>

// -------------------------
// Taskas3D metodų implementacija
// -------------------------

Taskas3D::Taskas3D(double x, double y, double z) : x(x), y(y), z(z) {}

double Taskas3D::getX() const {
    return x;
}

double Taskas3D::getY() const {
    return y;
}

double Taskas3D::getZ() const {
    return z;
}

std::string Taskas3D::to_string() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ", " << z << ")";
    return oss.str();
}

double Taskas3D::atstumas(const Taskas3D &kitas) const {
    double dx = x - kitas.x;
    double dy = y - kitas.y;
    double dz = z - kitas.z;
    return std::sqrt(dx * dx + dy * dy + dz * dz);
}

void Taskas3D::keiskTaska(double newX, double newY, double newZ) {
    x = newX; y = newY; z = newZ;
}

void Taskas3D::keiskX(double newX) { x = newX; }
void Taskas3D::keiskY(double newY) { y = newY; }
void Taskas3D::keiskZ(double newZ) { z = newZ; }

// -------------------------
// Lauzte3D metodų implementacija
// -------------------------

// Numatytojo konstruktorius: sukuria laužtę iš vieno taško (0,0,0)
Lauzte3D::Lauzte3D() : n(1) {
    taskai = new Taskas3D[1];
    taskai[0] = Taskas3D(0, 0, 0);
}

// Konstruktorius su parametrais: priima taškų skaičių ir masyvą
Lauzte3D::Lauzte3D(int n, const Taskas3D* lauzte) : n(n) {
    
    taskai = new Taskas3D[this->n];
    for (int i = 0; i < this->n; i++) {
        taskai[i] = lauzte[i];
    }
    
}

// Kopijos konstruktorius
Lauzte3D::Lauzte3D(const Lauzte3D& other) : n(other.n) {
    taskai = new Taskas3D[n];
    for (int i = 0; i < n; i++) {
        taskai[i] = other.taskai[i];
    }
}

// Destruktorius – atlaisvina dinamiškai rezervuotą atmintį
Lauzte3D::~Lauzte3D() {
    delete[] taskai;
}

// Get metodai
int Lauzte3D::getN() const {
    return n;
}

Taskas3D Lauzte3D::getTaskas(int index) const {
    if (index < 0 || index >= n)
        return taskai[0]; // Alternatyva: gali grąžinti klaidą arba numatytą reikšmę
    return taskai[index];
}

// Set metodas: pakeičia tašką nurodytame indekse
void Lauzte3D::setTaskas(int index, const Taskas3D& t) {
    if (index >= 0 && index < n) {
        taskai[index] = t;
    }
}

// to_string metodas: gražina laužtės taškų reprezentaciją
std::string Lauzte3D::to_string() const {
    std::ostringstream oss;
    oss << "Lauzte3D: [";
    for (int i = 0; i < n; i++) {
        oss << taskai[i].to_string();
        if (i < n - 1)
            oss << ", ";
    }
    oss << "]";
    return oss.str();
}

// Metodas, kuris suskaičiuoja laužtės ilgį (sudeda atstumus tarp nuoseklių taškų)
double Lauzte3D::ilgis() const {
    double sum = 0;
    for (int i = 0; i < n-1; i++) {
        sum += taskai[i].atstumas(taskai[i+1]);
    }
    return sum;
}
