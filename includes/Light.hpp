#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vect.hpp"
#include "Color.hpp"

class Light {
    Vect    origin;
    Color   color;

public:
    Light();
    Light(Vect o, Color c);

    Vect    getLightOri();
    Color   getLightCol();

    ~Light();
};

#endif