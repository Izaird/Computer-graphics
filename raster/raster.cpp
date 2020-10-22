#include "raster.h"

Raster::Raster(){
    memset(data, 0, 1920*1080*3);
}

void Raster::write(std::string file_name){
    std::ofstream my_file;
    my_file.open (file_name);
    my_file << "P6\n1920 1080 255\n";
    my_file.close();
    for(int y = 0; y<1080; y++){
        for(int x = 0; x<1920; x++){
            my_file <<data[x][y][0];
            my_file<<data[x][y][1];
            my_file<<data[x][y][2];
        }
    }
    my_file.close();
}