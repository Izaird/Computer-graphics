#include <cstring>
#include <iostream>


class Raster{
private:
    unsigned int rasterSizeX;
    unsigned int rasterSizeY;
public:
    //Default constructor
    Raster();

    //Constructor with values
    Raster(int x, int y);

    //Set a single pixel in the raster space.
    void setPixel(unsigned int x, unsigned int y,
                    unsigned char r,
                    unsigned char g,
                    unsigned char b);

    //Write data into a PPM file
    void write(void);

    //Naive algorithm to draw a line 
    void drawLineNaive(unsigned int x1, unsigned int y1,
                        unsigned int x2, unsigned int y2,
                        unsigned char r,
                        unsigned char g,
                        unsigned char b);

    //DDA algorithm to draw a line                     
    void drawLineDDA(unsigned int x1, unsigned int y1,
                        unsigned int x2, unsigned int y2,
                        unsigned char r,
                        unsigned char g,
                        unsigned char b);
                
    //Bresenham algorithm to draw a line 
    void drawLineBresenham(unsigned int x1, unsigned int y1,
                        unsigned int x2, unsigned int y2,
                        unsigned char r,
                        unsigned char g,
                        unsigned char b);
};