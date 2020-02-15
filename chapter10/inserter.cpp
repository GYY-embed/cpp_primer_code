#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main() 
{
    vector<int> v1{1, 2, 2, 2, 3, 1, 4, 4, 6, 3, 7, 8, 4};
    list<int> l1;
    unique_copy(v1.begin(), v1.end(), back_inserter(l1));
    for(auto i : l1)
        cout << i << " ";
    cout << endl;
    return 0;
}