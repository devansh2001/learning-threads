#include <iostream>
#include <stdio.h>
#include <thread>

int num = 0;
std::mutex m;

void increment() {
    std::cout << "In increment\n";
    std::this_thread::sleep_for(std::chrono::seconds(10));
    m.lock();
    num++;
    m.unlock();
    std::cout << "Going out\n";
}

int main() {
    int max = 1000;
    std::thread arr[max];
    for (int i = 0; i < max; i++) {
        // std::thread temp(increment);
        // temp.join();
        arr[i] = std::thread(increment);
    }
    for (int i = 0; i < max; i++) {
        arr[i].join();
    }
    
    // std::thread t2(increment);
    // t1.join();
    // std::cout << num << std::endl;
    // t2.join();
    std::cout << num << std::endl;
    // std::this_thread::sleep_for(std::chrono::seconds(6));
    return 0;
}