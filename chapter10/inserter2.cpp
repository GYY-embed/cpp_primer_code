#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <list>

using namespace std;

int main(int argc, const char** argv) 
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    list<int> l1, l2, l3;
    
    unique_copy(v1.begin(), v1.end(), front_inserter(l1));
    unique_copy(v1.begin(), v1.end(), back_inserter(l2));
    unique_copy(v1.begin(), v1.end(), inserter(l3,l3.begin()));

    for(auto i : l1)
        cout << i << " ";
    cout << endl;
    for(auto i : l2)
        cout << i << " ";
    cout << endl;
    for(auto i : l3)
        cout << i << " ";
    cout << endl;
    return 0;
}