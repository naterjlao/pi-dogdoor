#if 0
sudo apt update
sudo apt install gpiod libgpiod-dev libgpiod-doc g++


alternative
https://docs.sunfounder.com/projects/raphael-kit/en/latest/c_pi5/play_with_c.html
#endif

#include <gpiod.hpp>
#include <iostream>
#include <thread>
#include <chrono>

int main()
{
    const std::string GPIO_CHIP_NAME = "gpiochip0";
    const unsigned int GPIO_PIN = 17;

    try
    {
        ::gpiod::chip chip(GPIO_CHIP_NAME);
        ::gpiod::line_settings settings = chip.get_line_info(GPIO_PIN);
    } catch (const std::exception& e) {
        std::cerr << "Exception encountered: " << e.what() << "\n";
        return 1;
    }

    return 0;
}