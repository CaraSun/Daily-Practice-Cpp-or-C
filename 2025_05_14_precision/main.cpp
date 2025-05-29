#include <iostream>
#include <iomanip>
using namespace std;
class test{
public:

    void add1();
    void add2();
};
int a=0;
void test::add1(){

    a++;
}
void test::add2()
{
    a+=4;
}
int main()
{
    test ta;
    ta.add1();
    ta.add2();
    cout << a;
    return 0;
}