#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s("Hello,world!");
    decltype(s.size()) i = 0;
    // for(auto &c : s)
    // {
    //     c = 'X';
    // } 
    // while(i <= s.size())
    // {
    //     s[i] = 'X';
    //     i++;
    // }
    for(decltype(s.size()) j = 0; j<=s.size(); j++)
        s[j] = 'X';
    cout << s << endl;
    return 0;
}