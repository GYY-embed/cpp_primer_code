#include <iostream>
#include <forward_list>
#include <string>

using namespace std;

void search_insert(forward_list<string> & l1, string s1, string s2)
{
    auto prev = l1.before_begin();
    auto curr = l1.begin();

    while(curr != l1.end())
    {
        if(*curr == s1)
        {
            l1.erase_after(prev);
            curr = l1.insert_after(prev, s2);
            return;
        }
        else
        {
            prev = curr;
            ++curr;
        }    
    }
    l1.insert_after(prev, s2);
}

int main()
{
    forward_list<string> flist1{"hello", "world", "c++", "gyy"};
    search_insert(flist1, "world", "2020");
    for(auto i : flist1)
        cout << i << " ";
    cout << endl;

    search_insert(flist1, "cpp", "sx");
    for(auto i : flist1)
        cout << i << " ";
    cout << endl;

    return 0;
}