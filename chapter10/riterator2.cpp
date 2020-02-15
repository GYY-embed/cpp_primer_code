#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>


using namespace std;

int main(int argc, const char** argv) 
{
    list<int> v1{0, 2, 3, 0, 5, 6, 7, 0, 9};

    auto last_z = find(v1.crbegin(), v1.crend(), 0);
    last_z++;

    int p = 1;
    for(auto iter = v1.begin(); iter != last_z.base(); iter++, p++);

    if(p >= v1.size())
        cout << "没有0";
    else
        cout << "at :" <<  p << endl;

    return 0;
}