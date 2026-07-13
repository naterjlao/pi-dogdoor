// https://docs.sunfounder.com/projects/raphael-kit/en/latest/c_pi5/play_with_c.html
// https://pinout.xyz/pinout/wiringpi

#include <wiringPi.h>
#include <stdio.h>

int main()
{
    if (wiringPiSetup() == -1)
    {
        perror("wiringPiSetup FAILED");
        return 1;
    }
    const int WIRING_PI_PIN = 15;

    pinMode(WIRING_PI_PIN, OUTPUT);
    while (true)
    {
        digitalWrite(WIRING_PI_PIN, LOW);
        delay(500);
        digitalWrite(WIRING_PI_PIN, HIGH);
        delay(500);
    }
    return 0;
}