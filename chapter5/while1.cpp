#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    string currentstr, laststr{0}, maxstr;
    unsigned int currentcnt = 0, maxcnt = 0;
    
    while(cin >> currentstr)
    {
        if(currentstr == laststr)
            ++currentcnt;
        else
            currentcnt = 0;

        if(currentcnt >= maxcnt)
        {
            maxcnt = currentcnt;
            maxstr = currentstr;
        }    
        laststr = currentstr;
    }
    if(maxcnt == 0)
        cout << "There is no str repeat !" << endl;
    else
        cout << "The str : " << maxstr << endl << "repeat num : " << maxcnt + 1 << endl;
    return 0;
}