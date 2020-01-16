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
        v1.push_back(temp);
    for(auto it = v1.begin(); it != v1.end(); ++it)
    {
        // string s = *it;
        // for(auto it1 = s.begin(); it1 != s.end(); it1++)
        //     *it1 = toupper(*it1);
        // *it = s;
        for(auto it1 = (*it).begin(); it1 != (*it).end(); it1++)
            *it1 = toupper(*it1);
    }
    for(auto it = v1.begin(); it != v1.end(); ++it)
        cout << *it << endl;
    return 0;
}