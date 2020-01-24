#include <iostream>
#include <string>

using std::string;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    char newch, prech = '\0';
    unsigned int cnt_ff = 0, cnt_fl = 0, cnt_fi = 0;

    while (cin >> newch)
    {
        if(prech == 'f')
        {
            switch(newch)
            {
                case 'f':
                    ++cnt_ff;
                    break;
                case 'l':
                    ++cnt_fl;
                    break;
                case 'i':
                    ++cnt_fi;
                    break;
            }
        }
        prech = newch;
    }
    
    cout << "number of ff is : " << cnt_ff << endl;
    cout << "number of fl is : " << cnt_fl << endl;
    cout << "number of fi is : " << cnt_fi << endl;

    return 0;
}