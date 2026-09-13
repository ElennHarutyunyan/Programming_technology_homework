#include <iostream>
#include <thread>
using namespace std;
class Singleton{
private:
    static Singleton* instance;

    Singleton(){
        cout<<"Singleton created";
    }
public:
    static Singleton* getInstance(){
        if(instance == nullptr){
            instance = new Singleton();
        }
        return instance;
    }
};
Singleton * Singleton::instance = nullptr;

void task(){
    Singleton * s = Singleton::getInstance();
    cout<< s << "\n";
}
int main(){
    thread t1(task);
    thread t2(task);
    t1.join();
    t2.join();
    return 0;
}