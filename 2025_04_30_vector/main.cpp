#include <iostream>
#include <vector>
using namespace std;
int main(){
    vector<int> vInt;

    for(int i=0; i < 5; i++)
    {
        vInt.push_back(i);
        cout<<vInt.capacity()<<endl;
    }
    vector<int> vTmp(vInt);
    cout<<vTmp.capacity()<<endl;
    return 0;
}