#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    int ia[] = {0, 1, 1, 2, 3, 5, 8, 13, 21, 55, 89};
    vector<int> v1;
    list<int> l1;

    for(auto i : ia)
        v1.push_back(i);
    
    for(auto i : ia)
        l1.push_back(i);

    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    for(auto i : l1)
        cout << i << " ";
    cout << endl;

    for(auto it = v1.begin(); it != v1.end(); ++it)
    {
        if(*it % 2 ==1)
            it = --(v1.erase(it));
    }
    for(auto it = l1.begin(); it != l1.end(); ++it)
    {
        if(*it % 2 ==0)
            it = --(l1.erase(it));
    }
    
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    for(auto i : l1)
        cout << i << " ";
    cout << endl;

    return 0;
}