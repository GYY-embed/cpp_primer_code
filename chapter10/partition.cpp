#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool isfive(const string &s)
{
    return (s.size()>=5) ? 1 : 0;
}

int main()
{
    vector<string> v1{"hello", "world", "gyy", "hello", "c++", "2020", "world", "vc", "wcg", "amd", "intel"};
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    auto end_part = partition(v1.begin(), v1.end(), isfive);
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    v1.erase(end_part, v1.end());
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
}