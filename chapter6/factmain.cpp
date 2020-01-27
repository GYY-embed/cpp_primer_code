#include <iostream>
#include "myfact.h"
using namespace std;

int main()
{
    int num, retval;
    cout << "Please input a number : ";
    while(cin >> num)
    {    
        if(num >= 1)
        {
            retval = fact(num);
            cout << "result : " << retval << endl;
        }
        else
        {
            cout << "The number must bigger than 1!!" << endl;
        }
    }
    return 0;
}