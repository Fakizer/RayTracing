#include "Camera.hpp"

Camera::Camera() {}

Camera::Camera(Vect o, Vect la) : origin(o), look_at(la) {
    this->cw = origin.add(look_at.negative()).normalize();
    this->cu = cw.negative().crossProduct(Vect(0, 0, 1)).normalize();
    this->cv = cw.negative().crossProduct(cu);
}

void        Camera::calcRay(double xamnt, double yamnt) {
    Vect dir = cw.negative().add(cu.mult(xamnt - 0.5).add(cv.negative().mult(yamnt - 0.5))).normalize();

    this->ray = Ray(origin, dir);
}

Ray         Camera::getCameraRay() { return ray; }

Camera::~Camera() {}
