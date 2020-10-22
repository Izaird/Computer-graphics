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
    /* Line drawing algorithm
    Line equation:
    y = m*x + b
    * if you change x, you also get y values.
    */

   double m = (double)(y2-y1)/(double)(x2-x1);
   double be = (double)y1-(m * x1);
   unsigned int y = 0, x=0;
   // Iteration:    x1 < x2
   setPixel(x1, y1, r, g, b);
   setPixel(x2, y2, r, g, b);

    if(x1<x2){
        for(x = x1+1; x<=x2; x++){
        y = (unsigned int)(m*x + be);
        setPixel(x, y, r, g, b);
        }
    }
    else{
        for(x = x2+1; x<=x1; x++){
        y = (unsigned int)(m*x + be);
        setPixel(x, y, r, g, b);
        }   
    }
}

void Raster::drawLineDDA(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char r, unsigned char g, unsigned char b){
    double m = (double)(y2-y1)/(double)(x2-x1); //slope
    double be = (double)y1 - (m*x1) ;
    unsigned int x = 0;
    unsigned int y = 0;

    setPixel(x1, y1, r, g, b);
    setPixel(x2, y2, r, g, b);
       
    y = m*x1 + be;//Starting value
    for( x=x1+1 ; x<x2 ; x++) {
        y = y + m;
        setPixel(x, y, r, g, b);
    } 
}

void Raster::drawLineBresenham(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char r, unsigned char g, unsigned char b){
      double m = (double)(y2-y1)/(double)(x2-x1); //slope
      double be = (double)y1 - (m*x1) ;
      unsigned int x = 0;
      unsigned int y = 0;
      int dx = x2 - x1;
      int dy = y2 - y1;  
      int p = 2*dy-dx;  /// change 2* using bit operation.
      int updateUp    = 2*dy;          // -
      int updateRight = 2*dy-2*dx;     // +
      setPixel(x1, y1, r, g, b);
      setPixel(x2, y2, r, g, b);    //            ***  
      y = m*x1 + be;                ///y1-> ***
      for( x = x1 + 1 ; x < x2 ; x++ ) {   // deltaX = 1
        if( p < 0 ) { // < decision parameter
          y++;
          p += updateUp;    // < update
        } else {
          p += updateRight; // < update
        }   // p = -++-++---+++-+++---  /// <<< goal
        setPixel(x, y, r, g, b); /// raster space array[0][0];
      }     
}