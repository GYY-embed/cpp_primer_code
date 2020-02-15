#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char** argv) 
{
    int num = 20;
    auto add1 = [](int a, int b) { return a + b; };
    auto add2 = [num](int a) { return a + num; };
    cout << add1(5, 10) << endl; 
    cout << add2(5) << endl;
    return 0;
}