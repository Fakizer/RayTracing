#ifndef CAMERA_HPP
#define CAMERA_HPP

#include "Ray.hpp"

class Camera {
    Vect    origin;
    Vect    look_at;
    Vect    cw, cu, cv;
    Ray     ray;

public:
    Camera();
    Camera(Vect o, Vect la);

    void    calcRay(double xamnt, double yamnt);
    Ray     getCameraRay();

    ~Camera();

};

#endif
