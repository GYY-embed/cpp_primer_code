#include <iostream>

using std::cout;
using std::cin;
using std::endl;

int main()
{
    int x[10];
    int *p = x;
    cout << sizeof(int) << endl;
    cout << sizeof(int *) << endl;
    cout << sizeof(x)/sizeof(*x) << endl;
    cout << sizeof(p)/sizeof(*p) << endl;
    return 0;
}