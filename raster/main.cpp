#include "raster.h"

int main(){
    Raster raster = Raster();
    raster.drawLineNaive(1000,1000, 0, 0, 255, 0, 255);
    // raster.drawLineNaive(0,0, 1000, 1000, 255, 255, 255);
    raster.drawLineNaive(0,0, 100, 1000, 255, 255, 255);
    // raster.drawLineDDA(0,0, 1000, 500, 255, 0, 255);
    // raster.drawLineBresenham(0,0, 1000, 1000, 0, 255, 255);
    raster.write("test.ppm");
    std::cout << "test" << std::endl;
    

    return 0;
}