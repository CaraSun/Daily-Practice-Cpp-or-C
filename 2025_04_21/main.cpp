#include <iostream>
#include <thread>
#include <mutex>

std::mutex mtx;
int shared_resource = 0;

void increment()
{
    for(int i = 0; i < 10000; ++i)
    {
        mtx.lock();
        shared_resource++;
        shared_resource++;
        shared_resource--;
        mtx.unlock();
    }
}

int main(){
    std::thread th1(increment);
    std::thread th2(increment);


    th1.join();
    th2.join();
    std::cout<<shared_resource<<std::endl;
    return 0;
}