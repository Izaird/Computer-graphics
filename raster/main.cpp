#include "raster.h"

int main(){
    Raster raster = Raster();
    raster.write("test.ppm");
    std::cout << "test" << std::endl;
    

    return 0;
}