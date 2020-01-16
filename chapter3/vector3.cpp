#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<string> v1;
    string temp;
    while(cin >> temp)
    {
        v1.push_back(temp);
    }
    cout << "Finish !!" << endl;
    for(decltype(v1.size()) i=0;i<v1.size();i++)
    {
        //cout << "OK1" << endl;
        for(auto &c : v1[i])
        {
            c = toupper(c);
           //cout << "OK2" << endl;
        }
    }
    for(auto c: v1)
        cout << c << endl;
    return 0;
}