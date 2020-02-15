#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>


using namespace std;

int main(int argc, const char** argv) 
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8, 9};
    for(auto r_iter = v1.crbegin(); r_iter != v1.crend(); ++r_iter)
        cout << *r_iter << endl;
    for(auto iter = v1.cend()-1; iter >= v1.cbegin(); --iter)
        cout << *iter << endl;
    return 0;
}