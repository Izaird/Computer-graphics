#include "raster.h"

int main(){
    Raster raster = Raster();
    raster.drawLineNaive(1000,1000, 100, 100, 255, 0, 255);
    raster.drawLineNaive(0,0, 1000, 800, 255, 255, 255);
    raster.drawLineNaive(0,0, 100, 1000, 255, 255, 255);
    raster.drawLineNaive(1500,100, 300, 400, 255, 255, 255);
    raster.drawLineNaive(100,1000, 1500, 100, 255, 255, 255);
    raster.drawLineNaive(500, 100, 500, 1000, 255, 255, 255);
    raster.drawLineNaive(100, 500, 1000, 500, 255, 255, 255);
    // raster.drawLineDDA(0,0, 1000, 500, 255, 0, 255);
    // raster.drawLineBresenham(0,0, 1000, 1000, 0, 255, 255);
    raster.write("test.ppm");
    std::cout << "test" << std::endl;
    

    return 0;
}