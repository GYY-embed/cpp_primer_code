#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string input;
    // while(getline(cin,input))
    // {
    //     cout << endl << input << endl;
    // }
    while(cin >> input)
    {
        cout << endl << input << endl;
    }
    return 0;
}