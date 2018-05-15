#include "Color.hpp"

Color::Color() : red(0.5), green(0.5), blue(0.5) {}

Color::Color(double r, double g, double b, double s) {
    red = r;
    green = g;
    blue = b;
    special = s;
}

double      Color::getColorRed() { return red; }
double      Color::getColorGreen() { return green; }
double      Color::getColorBlue() { return blue; }
double      Color::getColorSpecial() { return special; }

void        Color::setColorRed(double r) { red = r; }
void        Color::setColorGreen(double g) { green = g; }
void        Color::setColorBlue(double b) { blue = b; }
void        Color::setColorSpecial(double s) { special = s; }



Color::~Color() {}