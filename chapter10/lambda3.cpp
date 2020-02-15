#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char** argv) 
{
    int count = 6;
    auto f = [&count] () -> bool
        {if(--count) return true; else return false;};
    bool ret = f();
    cout << ret << endl;
    while(ret)
    {
        cout << "OK" << endl;
        ret = f();
    }
    return 0;
}