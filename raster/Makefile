CFLAGS = -O0 -g
CC = g++
NumTest: main.o raster.o
	$(CC) $(CFLAGS) -o raster main.o raster.o

main.o: main.cpp
	$(CC) $(CFLAGS) -c main.cpp

raster.o: raster.cpp
	$(CC) $(CFLAGS) -c raster.cpp

clean: rm -f core *.o
