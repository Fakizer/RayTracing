#ifndef VECT_HPP
#define VECT_HPP

#include <cmath>

class Vect {
    double x, y ,z;

public:
    Vect();
    Vect(double x, double y, double z);

    double      getVectX();
    double      getVectY();
    double      getVectZ();

    Vect        mult(int k);
    Vect        negative();
    double      magnitude();
    Vect        normalize();
    Vect        add(Vect v1);
    double      dotProduct(Vect v1);
    Vect        crossProduct(Vect v1);

    ~Vect();
};

#endif