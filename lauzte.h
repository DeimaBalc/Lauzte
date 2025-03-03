#ifndef LAUZTE3D_H
#define LAUZTE3D_H

#include <string>
#include <sstream>
#include <cmath>

class Taskas3D {
private:
    double x, y, z;
public:
    
    Taskas3D(double x = 0, double y = 0, double z = 0);
    
    double getX() const;
    double getY() const;
    double getZ() const;
    
    std::string to_string() const;
    double atstumas(const Taskas3D &kitas) const;
    
    void setTaska(double x, double y, double z);
    void setX(double x);
    void setY(double y);
    void setZ(double z);
    
};

class Lauzte3D {
private:
    int n;             
    Taskas3D* taskuKoord;  
public:
    // Konstruktoriai ir destruktorius
    Lauzte3D();                                 // numatytasis konstruktorius (sukuria laužtę iš vieno taško (0,0,0))
    Lauzte3D(int n, const Taskas3D* taskai);     // konstruktorius su parametrais
    Lauzte3D(const Lauzte3D& other);             // kopijos konstruktorius
    ~Lauzte3D();                                // destruktorius

   
    int getN() const;
    Taskas3D getTaskas(int index) const;
    void setTaskas(int index, const Taskas3D& t);

    
    std::string to_string() const;
    double ilgis() const; 
};

#endif 
