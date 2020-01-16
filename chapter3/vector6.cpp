//3.24
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1;
    int temp;
    while(cin >> temp)
        v1.push_back(temp);
    cout << "first : " << endl;
    for(auto it = v1.begin(); it != v1.end()-1 ; ++it)
    {   
        cout << *it + *(it + 1) << "\t";
    }
    cout << endl;
    cout << "second : " << endl;
    for(auto it = v1.begin(); it != v1.begin() + (v1.size()/2) ; ++it)
    {   
        cout << *it + *(v1.end()-(it-v1.begin())-1) << "\t";
    }
    if(v1.size()%2 != 0)
    {
        cout << *(v1.begin()+(v1.size()/2)) << endl;
    }
    else 
        cout << endl;
    return 0;
}