#include <iostream>
#include <thread>

const uint32_t maxClientCount = 10;

void clientIncrease(uint32_t& clientCount)
{
    while (clientCount < maxClientCount)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000)); // задержка на 1 сек
        ++clientCount;
        std::cout << "Client added. Total clients number:\t" << clientCount << std::endl;
    }
}

void clientDecrease(uint32_t& clientCount)
{
    while (clientCount > 0)
    {
        std::this_thread::sleep_for(std::chrono::milliseconds(2000)); // задержка на 2 сек
        --clientCount;
        std::cout << "Client deleted. Total clients number:\t" << clientCount << std::endl;
    }
}

int main()
{
    uint32_t clientCount = 2;
    std::cout << "Total clients number at the beginning:\t" << clientCount << std::endl;

    std::thread clientTread(clientIncrease, std::ref(clientCount));
    std::thread operTread(clientDecrease, std::ref(clientCount));

    clientTread.join();
    operTread.join();

    std::cout << "Total clients number at the end:\t" << clientCount << std::endl;
    return 0;
}

