#include <iostream>
using namespace std;
struct A1
{
    virtual ~A1() {}
};
struct A2
{
    virtual ~A2() {}
};
struct B1 : A1, A2 {};
int main()
{
    B1 d;
    A1* pb1 = &d;
    A2* pb2 = dynamic_cast<A2*>(pb1);  //L1
  //  A2* pb22 = static_cast<A2*>(pb1);  //L2
    A2* pb222 = reinterpret_cast<A2*>(pb1);
    return 0;
}