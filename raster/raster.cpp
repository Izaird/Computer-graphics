#include "raster.h"

Raster::Raster(){
    memset(data, 0, 1920*1080*3);
}

void Raster::setPixel(unsigned int x, unsigned int y, unsigned char r, unsigned char g, unsigned char b){
    if( x >= 1920 || y >= 1080) {
        return;
    }
    data[x][y][0] = r;
    data[x][y][1] = g;
    data[x][y][2] = b;
}

void Raster::randomPixels(unsigned int number_of_pixels){
    unsigned int x = 0;
    unsigned int y = 0;
    unsigned char r = 0x00;
    unsigned char g = 0x00;
    unsigned char b = 0x00;
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distX(0,1919);
    std::uniform_int_distribution<unsigned int> distY(0,1079);
    std::uniform_int_distribution<unsigned char> distC(0x00,0xff);

    for(int i=0; i<number_of_pixels; i++) {
        x = distX(generator);
        y = distY(generator);
        r = distC(generator);
        g = distC(generator);
        b = distC(generator);
        this->setPixel(x,y,r,b,g);
    }

}

void Raster::write(std::string file_name){
    std::ofstream my_file;
    my_file.open (file_name);
    my_file << "P6\n1920 1080 255\n";
    for(int y = 0; y<1080; y++){
        for(int x = 0; x<1920; x++){
            my_file<<data[x][y][0];
            my_file<<data[x][y][1];
            my_file<<data[x][y][2];
        }
    }
    my_file.close();
}

void Raster::drawLineNaive(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char r, unsigned char g, unsigned char b){
                            
                        }