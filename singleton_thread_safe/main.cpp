#include <iostream>
#include <thread>
using namespace std;

#include "Singleton.h"

Singleton* Singleton::pinstance_ = nullptr;;
std::mutex Singleton::mutex_;

void ThreadFoo() {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    Singleton* singleton = Singleton::GetInstance("FOO");
    std::cout << singleton->value() << "\n";
}

void ThreadBar() {
    std::this_thread::sleep_for(std::chrono::microseconds(1000));
    Singleton* singleton = Singleton::GetInstance("BAR");
    std::cout << singleton->value() << "\n";
}


int main() {
    std::cout << "If you see the same value, then singleton was reused (yay!\n" << 
    "If you see different values, then 2 singletons were created (booo!!\n\n" << 
    "RESULT:\n";

    std::thread t1(ThreadFoo);
    std::thread t2(ThreadBar);
    t1.join();
    t2.join();

    return 0;
}
