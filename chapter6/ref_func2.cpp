#include <iostream>
#include <string>

using namespace std;

bool is_cap_letter(const string &s)
{
    for(auto c : s)
    {
        if(c >= 'A' && c <= 'Z')
            return true;
    }
    return false;
}

void up_to_low(string &s)
{
    for(auto &c : s)
    {
        if(isupper(c))
            c = tolower(c);
    }
}
int main()
{
    string str;
    cout << "Please input a string ";
    if(getline(cin,str))
    {
        auto ret = is_cap_letter(str);
        if(ret == true)
            cout << "Have !!" << endl;
        else 
            cout << "Don't have !!" << endl;
        up_to_low(str);
        cout << "Result : " << str << endl;
    }
    return 0;
}