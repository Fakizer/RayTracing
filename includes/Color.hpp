#ifndef COLOR_HPP
#define COLOR_HPP

class Color {
    double red, green, blue, special;

public:
    Color();
    Color(double r, double g, double b, double s);

    double      getColorRed();
    double      getColorGreen();
    double      getColorBlue();
    double      getColorSpecial();

    void        setColorRed(double r);
    void        setColorGreen(double g);
    void        setColorBlue(double b);
    void        setColorSpecial(double s);

    ~Color();
};

#endif
