#include <iostream>
using namespace std;
class A
{
public:
    A() 
    {
        cout << "create A !" << endl;
    }
    A(const A& para)
    {
        cout << "Copy constructor A !" << endl;
    }
    ~A()
    {
        cout << "~A" << endl;
    }
};
class B: public A
{
public:
    B(A &a):_a(a)
    {
        cout << "create B!" <<endl;
    }
    ~B()
    {
        cout << "~B" <<endl;
    }
private:
    A _a;
};
int main(){
    A a;
    B b(a);//通过a初始化b，调用拷贝构造函数
}