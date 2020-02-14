#include <iostream>
#include <string>

using namespace std;

string name_comp1(string s, const string &first, const string &last)
{
    string ret;
    s.insert(0, first);
    s.append(last);
    return s;
}


string name_comp2(string s, const string &first, const string &last)
{
    s.insert(0, first);
    s.insert(s.size(), last);
    return s;
}
int main(int argc, const char** argv) 
{
    cout << name_comp1("GYY", "Mr.", " III") << endl;
    cout << name_comp1("GYY", "Mr.", " III") << endl;
    return 0;
}