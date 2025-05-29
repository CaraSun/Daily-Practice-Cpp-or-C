#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;
struct Data
{
    float a;
    float b;
    float c;
};

int main()
{
    struct Data dataTest;
    dataTest.a = 0.1;
    dataTest.b = 0.2;
    dataTest.c = 0.3;

    int i=0;
    float count = 0;
    std::ofstream outFile("data.txt");
    for(;i<1000;++i)
    {
        dataTest.a += 0.1;
        dataTest.b += 0.1;
        dataTest.c += 0.1;
        count = dataTest.a + dataTest.b + dataTest.c;

        std::stringstream ss;
        ss << i << " " << dataTest.a << " "
            << dataTest.b << " " << dataTest.c << " " << count;
        outFile << ss.str() << std::endl; 
    }

    return 0;
}