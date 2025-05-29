#include <iostream>
using namespace std;
class Base{
public:
    virtual void f() { cout << "f()" << endl; }
    virtual void h() { cout << "h()" << endl; }
    virtual void g() { cout << "g()" << endl; }
    
};
class Derived : public Base
{
public:
    virtual void x()
    {
        cout << "x()" << endl;
    }

};

class Derive
{
public:
    virtual void m() { cout << "m" << endl; }
    virtual void f() { cout << "Derive::f()" << endl; }
};



int main(){
    Derive t;
    /*
	(     ((void(*)())*((int*)(*((int*)&t)) + 0))   )     ();
	(     ((void(*)())*((int*)(*((int*)&t)) + 1))   )     ();
	(	  ((void(*)())*((int*)(*((int*)&t)) + 2))	)     ();
          */
        // 获取虚函数表指针（vptr）
    // 注意：vptr 的类型和位置是编译器实现的细节
    void** vptr = *(void***)&t;
 
    // 通过虚函数表调用虚函数
    // 假设虚函数表中函数的偏移量是 0、1、2
    void (*funcPtr)() = nullptr;
 
    // 调用 f()
    funcPtr = (void(*)())vptr[0];
    funcPtr();
 
    // 调用 g()
    funcPtr = (void(*)())vptr[1];
    funcPtr();
 
    // 调用 h()
    //funcPtr = (void(*)())vptr[2];
    //funcPtr();

    //funcPtr = (void(*)())vptr[3];
    //funcPtr();
      
    return 0;
}
// 派生类未覆盖基类虚函数
// 虚函数按照声明顺序放于表中
// 父类的虚函数在子类的虚函数前面

//派生类覆盖基类虚函数
//虚函数表中派生类覆盖的虚函数的地址被放在了基类相应的函数原来的位置
//派生类中没有覆盖的虚函数沿用基类的
