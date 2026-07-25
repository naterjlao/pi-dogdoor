all: image-detect-test gpio-test gpio-ON gpio-OFF

image-detect-test: image-detect-test.cpp
	g++ -O3 image-detect-test.cpp -o image-detect-test `pkg-config --cflags --libs opencv4`

gpio-test: gpio-test.cpp
	g++ gpio-test.cpp -o gpio-test -lwiringPi

gpio-ON: gpio-ON.cpp
	g++ gpio-ON.cpp -o gpio-ON -lwiringPi

gpio-OFF: gpio-OFF.cpp
	g++ gpio-OFF.cpp -o gpio-OFF -lwiringPi

clean:
	rm -rvf image-detect-test gpio-test
