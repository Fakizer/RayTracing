#ifndef RAY_HPP
#define RAY_HPP

#include "Vect.hpp"

class Ray {
    Vect    origin;
    Vect    direction;

public:
    Ray();
    Ray(Vect o, Vect d);

    Vect    getRayOri();
    Vect    getRayDir();

    ~Ray();
};

#endif
