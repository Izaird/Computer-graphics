#include "raster.h"

int main(){
    Raster raster = Raster();
    raster.randomPixels(1000000);
    raster.write("test.ppm");
    std::cout << "test" << std::endl;
    

    return 0;
}