CFLAGS = -O0 -g
CC = g++
NumTest: main.o raster.o
	$(CC) $(CFLAGS) -O fhdRaster main.o raster.o
main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

turing.o: turing.cpp
	$(CC) #(CFLAGS) -c turing.cpp

clean: rm -f core *.o
