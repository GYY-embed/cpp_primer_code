#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <list>


using namespace std;

void elimDups(list<string> &words)
{
    for(auto i : words)
        cout << i << " ";
    cout << endl;
    words.sort();
    for(auto i : words)
        cout << i << " ";
    cout << endl;   
    words.unique();
    for(auto i : words)
        cout << i << " ";
    cout << endl;
}
int main(int argc, const char** argv) 
{
    list<string> l1{"hello", "world", "gyy", "hello", "c++", "2020", "world", "vc", "wcg", "amd", "intel"};
    elimDups(l1);

    return 0;
}