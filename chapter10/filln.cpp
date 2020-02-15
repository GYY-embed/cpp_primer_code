#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;
int main(int argc, const char** argv) 
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    fill_n(v1.begin(), v1.size(), 0);
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    return 0;
}