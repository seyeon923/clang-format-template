#include <iostream>
#include <sstream>
#include <thread>

class A {
public:
    A() = default;
    A(int val) : val_(val) {}

private:
    int val_;
};

int main() {
    A* pa = new A();
    delete pa;

    std::thread th([]() {
        std::ostringstream ss;
        ss << "Thread: " << std::this_thread::get_id() << std::endl;
        std::cout << ss.str();
    });

    std::ostringstream ss;
    ss << "Main: " << std::this_thread::get_id() << std::endl;
    std::cout << ss.str();

    th.join();

    return 0;
}