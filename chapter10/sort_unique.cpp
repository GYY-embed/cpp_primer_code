#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

bool isshort(const string &s1, const string &s2)
{
    return s1.size() < s2.size();
}
int main(int argc, const char** argv) 
{
    vector<string> v1{"hello", "world", "gyy", "hello", "c++", "2020", "world", "vc", "wcg", "amd", "intel"};
    for(auto i : v1)
        cout << i << " ";
    cout << endl;
    elimDups(v1);
    for(auto i : v1)
        cout << i << " ";
    cout << endl;   
    stable_sort(v1.begin(), v1.end(), isshort);
    for(auto i : v1)
        cout << i << " ";
    cout << endl;     
    return 0;
}