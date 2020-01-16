#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s("Hello,world!!!");
    decltype(s.size()) cnt = 0;
    for(auto c : s)
        if(ispunct(c))
            cnt++;
    cout << cnt << " punct in " << s << endl;
    for(auto &c : s)
        c = toupper(c);
    cout << s << endl;
    return 0;
}