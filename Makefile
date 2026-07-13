# TODO port to cmake
all: build/pi-dogdoor-driver

build/pi-dogdoor-driver: main.cpp
	mkdir -p build/
	g++ -O3 main.cpp -o build/pi-dogdoor-driver `pkg-config --cflags --libs opencv4` -lwiringPi

clean:
	rm -rvf build/