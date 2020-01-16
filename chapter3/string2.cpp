#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string s1,s2;
    cout << "Please input s1 : ";
    getline(cin,s1);
    cout << "Please input s2 : ";
    getline(cin,s2);
    if(s1 == s2)
        cout << "equal !!" << endl;
    else
    {
        if(s1 > s2)
            cout << "s1 is bigger ,s1 : "<<  s1 << endl;
        else
            cout << "s2 is bigger ,s2 : "<< s2 << endl;
    }
    if(s1.size() == s2.size())
        cout << "Length equal !!" << endl;
    else
    {
        if(s1.size() > s2.size())
            cout << "s1 is longer ,s1 : "<<  s1 << endl;
        else
            cout << "s2 is longer ,s2 : "<< s2 << endl;
    }   

    return 0;
}