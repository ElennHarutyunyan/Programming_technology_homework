#include <iostream>
#include <thread>

using namespace std;

class Singleton {
private:
    Singleton() {
        cout << "Singleton is created\n";
    }
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton&&) = delete;

public:
    static Singleton& getInstance() {
        static Singleton instance;
        return instance;
    }
};

void task() {
    Singleton& s = Singleton::getInstance();
    cout << &s << "\n";
}

int main() {
    thread t1(task);
    thread t2(task);
    
    t1.join();
    t2.join();
    
    return 0;
}