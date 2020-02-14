#include <iostream>
#include <list>
#include <string>
#include <vector>

using namespace std;

int main()
{
    list<char *> l1{"hello", "world", "gyy"};
    vector<string> v1;

    v1.assign(l1.cbegin(), l1.cend());

    for(auto i : v1)
        cout << i << "  ";
    cout << endl;
    return 0;

}
