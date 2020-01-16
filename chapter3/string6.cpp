#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s;
    cout << "Please input a string : " << endl;
    getline(cin, s);
    for(auto c : s)
        if(!ispunct(c))
            cout << c ;
    return 0;
}