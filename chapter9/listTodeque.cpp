#include <iostream>
#include <list>
#include <deque>

using namespace std;

int main()
{
    list<int> l1{1, 2, 3, 4, 5, 6, 7, 8};
    deque<int> d1, d2;

    for(auto it = l1.cbegin(); it != l1.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto i : l1)
    {
        if(i % 2 == 0)
            d1.push_back(i);
        else
            d2.push_back(i);
    }
    for(auto it = d1.cbegin(); it != d1.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    for(auto it = d2.cbegin(); it != d2.cend(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}