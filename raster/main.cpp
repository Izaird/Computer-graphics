#include "raster.h"

int main(){
    Raster raster = Raster();
    // raster.randomLines(10000);//naive method
    raster.drawLineDDA(0,0,1000,1000,255,255,255);
    raster.write("test.ppm");
    std::cout << "test" << std::endl;
    

    return 0;
}