#include <cstring>
#include <iostream>
#include <fstream>

//TODO: Make a constructor that recives size of the
//      raster(rasterSizeX, rasterSizeY)

class Raster{
private:
    unsigned char data[1920][1080][3];
public:
    //Default constructor
    Raster();


    //Set a single pixel in the raster space.
    void setPixel(unsigned int x, unsigned int y,
                    unsigned char r,
                    unsigned char g,
                    unsigned char b);


    //Write data into a PPM file
    void write(std::string fie_name);


    void randomPixels();

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