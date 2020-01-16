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
    cout << "first: " << endl;
    for(decltype(v1.size()) i=0; i<v1.size()-1; i++)
        cout << v1[i] + v1[i+1] << "\t";
    cout << endl;
    cout << "second: " << endl;
    for(decltype(v1.size()) i=0; i<v1.size()/2; i++)
        cout << v1[i] + v1[v1.size()-i-1] << "\t";
    if(v1.size()%2!=0)
        cout << v1[v1.size()/2] << endl;
    else
        cout << endl;
    return 0;
}