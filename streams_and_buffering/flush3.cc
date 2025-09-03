#include <iostream>
#include <thread>
#include <chrono>

int main() {
    std::cout << "Loading";
    for (int i = 0; i < 3; ++i) {        
        std::cout << "."; // Appends dots
        std::this_thread::sleep_for(std::chrono::seconds(1)); // Wait 1 second
    }
    std::cout << std::endl;
    return 0;
}