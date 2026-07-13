all: image-detect-test gpio-test

image-detect-test: image-detect-test.cpp
	g++ -O3 image-detect-test.cpp -o image-detect-test `pkg-config --cflags --libs opencv4`

gpio-test: gpio-test.cpp
	g++ gpio-test.cpp -o gpio-test -lwiringPi

clean:
	rm -rvf image-detect-test gpio-test