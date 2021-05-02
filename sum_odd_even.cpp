#include <stdio.h>
#include <iostream>
#include <thread>
#include <chrono>

// using namespace std;

double findSum(double max, bool isEven) {
    double sum = 0;
    for (int i = 0; i < max; i++) {
        // cout << sum << ", " << i << endl;
        if (i % 2 == 0) {
            sum += isEven ? i : 0;
        } else {
            sum += isEven ? 0: i;
        }
    }
    return sum;
}

int main() {
    auto start = std::chrono::high_resolution_clock::now();
    // cout << start << endl;
    double num = 300000000;
    double evenSum = findSum(num, true);
    double oddSum = findSum(num, false);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    
    std::cout << duration.count() << "micros" << std::endl;
    std::cout << "Sums are "<< evenSum << ", " << oddSum << std::endl;
    std::cout << "**" << std::endl;

    start = std::chrono::high_resolution_clock::now();

    int a = 5;

    std::thread t1(findSum, num, true);
    std::thread t2(findSum, num, false);
    t1.join();
    t2.join();

    end = std::chrono::high_resolution_clock::now();
    auto duration2 = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << duration2.count() << "micros" << std::endl;
    std::cout << "Sums are "<< evenSum << ", " << oddSum << std::endl;
    std::cout << "**" << std::endl;

    std::cout << "Difference factor: " << duration / duration2 << std::endl;

    return 0;
}

