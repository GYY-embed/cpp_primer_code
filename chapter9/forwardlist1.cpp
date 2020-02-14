#include <iostream>
#include <forward_list>

using namespace std;

int main()
{
    forward_list<int> flist1{1, 2, 3, 4, 5, 6, 7, 8};

    auto prev = flist1.before_begin();
    auto curr = flist1.begin();

    for(auto i : flist1)
        cout << i << " ";
    cout << endl;

    while(curr != flist1.end())
    {
        if(*curr % 2)
            curr = flist1.erase_after(prev);
        else
        {
            prev = curr;
            ++ curr;
        }
    }

    for(auto i : flist1)
        cout << i << " ";
    cout << endl;
}