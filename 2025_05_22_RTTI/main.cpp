#include <iostream>

using namespace std;

class Parent
{
public:
    Parent() {
        cout << "我是你父母" << endl;
    }

    virtual ~Parent() {
        cout << "父类析构" << endl;
    }
    virtual void come(){
        cout << "父母来了" << endl;
    }
};

class Son : public Parent
{
public:
    Son() {
        cout << "我是你儿子" << endl;
    }

    ~Son() override {
        cout << "儿子析构" << endl;
    }
    void come(){
        cout << "儿子来了" << endl;
    }
};

class Daughtor 
{
public:
    Daughtor() {
        cout << "我是你闺女" << endl;
    }

    ~Daughtor()  {
        cout << "闺女析构" << endl;
    }
    void come(){
        cout << "闺女来了" << endl;
    }
};

int main()
{
    Parent *p = new Son();

    Son *son = dynamic_cast< Son *> (p);
    if(son != nullptr)
    {
        cout << "p有son子类" << endl;
    }
    else
    {
        cout << "p没有son子类" << endl;
    }

    Daughtor *daughtor = dynamic_cast< Daughtor *> (p);
    if(daughtor != nullptr)
    {
        cout << "p有daughtor子类" << endl;
    }
    else
    {
        cout << "p没有daughtor子类" << endl;
    }


    if(typeid(p).name() ==  typeid(Parent*).name())
    {
        cout << "p指针是Parent类型" << endl; 
    }
    else if(typeid(p).name() ==  typeid(Son*).name())
    {
        cout << "p指针是Son类型" << endl; 
    } 

    if(typeid(*p).name() ==  typeid(Parent).name())
    {
        cout << "p指针指向的是Parent类型" << endl; 
    }
    else if(typeid(*p).name() ==  typeid(Son).name())
    {
        cout << "p指针指向的是Son类型" << endl; 
    } 

    delete p;
    
    return 0;
}