#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1{1,2,3,4,5,6,7,8};
    for(auto &c : v1)
        (c%2==1)? c*=2 : c=c;
    for(auto c : v1)
        cout << c << " ";
    cout << endl;
    return 0;
}