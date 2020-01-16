#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int temp;
    vector<int> v1;
    while(cin >> temp)
    {
        v1.push_back(temp);
    }
    cout << "Finish!" << endl;
    for(auto c : v1)
        cout << c << "\t";
    cout << endl;
    return 0;
}