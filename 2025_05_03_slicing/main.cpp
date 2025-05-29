#include <iostream>
using namespace std;
class Base{
public:
    virtual void printError()
    {
        cout << "基类方法!" << endl;
    }
    
};
class Derived : public Base
{
public:
    void printError()
    {
        cout << "派生类方法!" << endl;
    }

};
// 静态联编,如果基类成员函数不是虚函数，则输出基类方法
// 如果基类成员函数是虚函数，则是动态绑定，输出派生类方法
void test()
{
	Base *ex = new Derived(); //静态联编导致子类对象调用基类方法，而不是子类方法
	ex->printError(); //输出基类方法！
}
// 对象切割,
void testSlice(Base obj)
{
    obj.printError();
}
// 引用传递
void testRef( Base& obj) {  // 引用传递
    obj.printError();  // 输出取决于 obj 的实际类型
}
int main(){
    test();
    Derived d;
    testSlice(d);//当把一个派生类对象用值传递的方式赋给基类对象时，会发生对象切割
    testRef(d); 
    return 0;
}

