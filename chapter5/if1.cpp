#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    char ich;
    int cnt = 0;

    cout << "Please input a paragraph of text : ";

    while(cin >> ich)
    {
        if(ich == 'a' || ich == 'e' || ich == 'i' || ich == 'o' || ich == 'u')
            ++cnt;
    }
    cout << "vowe cnt : " << cnt << endl; 
    return 0;
}