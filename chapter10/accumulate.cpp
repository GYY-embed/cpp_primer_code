#include <algorithm>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main(int argc, const char** argv) 
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    cout << "sum : " << accumulate(v1.cbegin(), v1.cend(), 0) << endl;
    return 0;
}