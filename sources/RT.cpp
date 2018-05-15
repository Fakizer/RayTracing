#include <iostream>
#include <fstream>
#include <sstream>

#include <vector>
#include <string>
#include <cmath>
#include <limits>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include "Camera.hpp"
#include "Light.hpp"

using namespace std;

struct RGBType {
    double r;
    double g;
    double b;
};

void    savebmp (const char *filename, int w, int h, int dpi, RGBType *data) {
    FILE *f;
    int k = w*h;
    int s = 4*k;
    int filesize = 54 + s;

    double factor = 39.375;
    int m = static_cast<int>(factor);

    int ppm = dpi * m;

    unsigned char bmpfileheader[14] = {'B','M', 0,0,0,0, 0,0,0,0, 54,0,0,0};
    unsigned char bmpinfoheader[40] = {40,0,0,0, 0,0,0,0, 0,0,0,0, 1,0,24,0};

    bmpfileheader[ 2] = (unsigned char) (filesize);
    bmpfileheader[ 3] = (unsigned char) (filesize>>8);
    bmpfileheader[ 4] = (unsigned char) (filesize>>16);
    bmpfileheader[ 5] = (unsigned char) (filesize>>24);

    bmpinfoheader[ 4] = (unsigned char) (w);
    bmpinfoheader[ 5] = (unsigned char) (w>>8);
    bmpinfoheader[ 6] = (unsigned char) (w>>16);
    bmpinfoheader[ 7] = (unsigned char) (w>>24);

    bmpinfoheader[ 8] = (unsigned char) (h);
    bmpinfoheader[ 9] = (unsigned char) (h>>8);
    bmpinfoheader[ 10] = (unsigned char) (h>>16);
    bmpinfoheader[ 11] = (unsigned char) (h>>24);

    bmpinfoheader[ 21] = (unsigned char) (s);
    bmpinfoheader[ 22] = (unsigned char) (s>>8);
    bmpinfoheader[ 23] = (unsigned char) (s>>16);
    bmpinfoheader[ 24] = (unsigned char) (s>>24);

    bmpinfoheader[25] = (unsigned char)(ppm);
	bmpinfoheader[26] = (unsigned char)(ppm>>8);
	bmpinfoheader[27] = (unsigned char)(ppm>>16);
	bmpinfoheader[28] = (unsigned char)(ppm>>24);
	
	bmpinfoheader[29] = (unsigned char)(ppm);
	bmpinfoheader[30] = (unsigned char)(ppm>>8);
	bmpinfoheader[31] = (unsigned char)(ppm>>16);
	bmpinfoheader[32] = (unsigned char)(ppm>>24);

    f = fopen(filename,"wb");
	
	fwrite(bmpfileheader,1,14,f);
	fwrite(bmpinfoheader,1,40,f);
	
	for (int i = 0; i < k; i++) {
		RGBType rgb = data[i];
		
		double red = (data[i].r) * 255;
		double green = (data[i].g) * 255;
		double blue = (data[i].b) * 255;
		
		unsigned char color[3] = {(int)floor(blue), (int)floor(green), (int)floor(red)};
		
		fwrite(color,1,3,f);
	}
	
	fclose(f);
}

int     thisone;

int     main() {
    cout << "rendering ..." << endl;

    int     dpi = 72;
    int     width = 1024;
    int     height = 720;
    int     n = width * height;
    double  aspectratio = width / height;
    RGBType *pixels = new RGBType[n];

    Color white_light (1.0, 1.0, 1.0, 0);
	Color pretty_green (0.5, 1.0, 0.5, 0.3);
	Color maroon (0.5, 0.25, 0.25, 0);
	Color tile_floor (1, 1, 1, 2);
	Color gray (0.5, 0.5, 0.5, 0);
	Color black (0.0, 0.0, 0.0, 0);

    Light lig(Vect(200, 0, 0), white_light);
    Camera cam(Vect (200, 0, 0), Vect (0, 0, 0));
    // Vect X(1, 0, 0);
    // Vect Y(0, 1, 0);
    // Vect Z(0, 0, 1);

    double xamnt, yamnt;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            thisone = x * height + y;

            if (width > height) {
                xamnt = ((x+0.5)/width)*aspectratio - (((width-height)/(double)height)/2);
                yamnt = ((height - y) + 0.5)/height;
            }
            else if (height > width) {
                xamnt = (x + 0.5)/ width;
                yamnt = (((height - y) + 0.5)/height)/aspectratio - (((height - width)/(double)width)/2);
            }
            else {
                xamnt = (x + 0.5)/width;
                yamnt = ((height - y) + 0.5)/height;
            }

            cam.calcRay(xamnt, yamnt);

            pixels[thisone].r = 23;
            pixels[thisone].g = 222;
            pixels[thisone].b = 10;
        }
    }

    savebmp("scene.bmp", width, height, dpi, pixels);

    return 0;
}
