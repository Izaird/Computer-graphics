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
void Raster::randomLines(unsigned int number_of_lines){
    unsigned int x1, x2, y1, y2;
    unsigned char r, g, b;
    std::default_random_engine generator;
    std::uniform_int_distribution<unsigned int> distX(0,1919);
    std::uniform_int_distribution<unsigned int> distY(0,1079);
    std::uniform_int_distribution<unsigned char> distC(0x00,0xff);

    for(int i=0; i<number_of_lines; i++) {
        x1 = distX(generator);
        x2 = distX(generator);
        y1 = distY(generator);
        y2 = distY(generator);
        r = distC(generator);
        g = distC(generator);
        b = distC(generator);
        drawLineNaive(x1,y1,x2,y2,r,g,b);
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
    std::cout << abs(x2-x1) << " " << abs(y2-y1)<< std::endl;
    if(x1==x2){
        setPixel(x1, y1, r, g, b);
        setPixel(x2, y2, r, g, b);
        if(y1>y2){
            unsigned int temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        unsigned int y=0, x=x1;
        for(y = y1+1; y<=y2; y++){
            setPixel(x, y, r, g, b);
        }
    }
    else if(abs(x2-x1) >= abs(y2-y1)){
        setPixel(x1, y1, r, g, b);
        setPixel(x2, y2, r, g, b);
        if(x1>x2){
            unsigned int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        double m = (double)((int)y2-(int)y1)/(double)((int)x2-(int)x1);
        double be = (double)y1-(m * x1);
        unsigned int y = 0, x=0;
        // Iteration:    x1 < x2

        for(x = x1+1; x<=x2; x++){
            y = (unsigned int)(m*x + be);
            setPixel(x, y, r, g, b);
        }
    }
    else{    
        setPixel(x1, y1, r, g, b);
        setPixel(x2, y2, r, g, b);
        if(y1>y2){
            unsigned int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        double m = (double)((int)y2-(int)y1)/(double)((int)x2-(int)x1);
        double be = (double)y1-(m * x1);
        unsigned int y = 0, x=0;
        // Iteration:    x1 < x2

        for(y = y1+1; y<=y2; y++){
            x = (y-be)/m;
            setPixel(x, y, r, g, b);
        }

    }

}



void Raster::drawLineDDA(unsigned int x1, unsigned int y1, unsigned int x2, unsigned int y2, unsigned char r, unsigned char g, unsigned char b){
    /* DDA (Digital Differential analysis )
        y = m*x + be;      // 1st
    next y = m*(x+1) + be;  // 2nd
    next y = m*x + m + be
    next y = m*x + be + m
    next y = y + m  /// << result of the DDA.
    */


    setPixel(x1, y1, r, g, b);
    setPixel(x2, y2, r, g, b);
   //Vertical line 
    if(x1==x2){
        if(y1>y2){
            unsigned int temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        unsigned int y=0, x=x1;
        for(y = y1+1; y<=y2; y++){
            setPixel(x, y, r, g, b);
        }
    }
    else if(abs(x2-x1) >= abs(y2-y1)){
        if(x1>x2){
            unsigned int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }
        double m = (double)((int)y2-(int)y1)/(double)((int)x2-(int)x1);
        double be = (double)y1-(m * x1);
        unsigned int x=0;
        float y = 0;
        y = m*x1 + be;//Starting value

        for(x = x1+1; x<=x2; x++){
            y = y + m;
            setPixel(x, (unsigned int)y, r, g, b);
        }
    }
    else{    
        if(y1>y2){
            unsigned int temp;
            temp = x1;
            x1 = x2;
            x2 = temp;
            temp = y1;
            y1 = y2;
            y2 = temp;
        }

        double m = (double)((int)y2-(int)y1)/(double)((int)x2-(int)x1);
        double be = (double)y1-(m * x1);
        unsigned int y = 0;
        float x = 0;
        x = (y1-be)/m; //Starting value

        for(y = y1+1; y<=y2; y++){
            x = x + 1/m;
            setPixel((unsigned int)x, y, r, g, b);
        }

    }

}