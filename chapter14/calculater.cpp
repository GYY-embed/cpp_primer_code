#include <iostream>
#include <map>
#include <string>
#include <algorithm>
#include <functional>

using namespace std;

map<string, function<int (int, int)>> binOps = {
    { "+", plus<int>() },
    { "-", minus<int>() },
    { "*", multiplies<int>() },
    { "/", divides<int>() },
    { "%", modulus<int>() },
};

int main(int argc, char const *argv[])
{
    int left, right;
    string op;
    cin >> left >> op >> right;
    cout << binOps[op](left, right) << endl;
    
    return 0;
}
