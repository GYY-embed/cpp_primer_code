#include <iostream>
#include <string>
#include <vector>

using namespace std;

int my_add(int a, int b)
{
    return a+b;
}

int my_sub(int a, int b)
{
    return a-b;
}

int my_multiply(int a, int b)
{
    return a*b;
}

int my_except(int a, int b)
{
    return a/b;
}


int main()
{
    int a = 10, b = 5;
    decltype(my_add) *p1 = my_add, *p2 = my_sub, *p3 = my_multiply, *p4 = my_except;
    vector<decltype(my_add) *> VF = {p1, p2, p3, p4};
    for(auto i : VF)
        cout << i(a,b) << endl;
    return 0;
}
