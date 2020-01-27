#include <iostream>
#include <string>

using namespace std;

string::size_type find_char (const string &s, char c, string::size_type &occures) 
{
    auto ret = s.size();
    occures = 0;
    for(decltype(ret) i = 0; i != s.size(); ++i)
    {
        if(s[i] == c)
        {
            if(ret == s.size())
                ret = i;
            ++occures;
        }
    }
    return ret;
}

int main()
{
    string str;
    string::size_type occures, position;
    cout << "Please input a string : ";
    getline(cin, str);
    position = find_char(str, 'o', occures);
    cout << "position : " << position+1 << " occ_num : " << occures << endl;
    return 0;
}