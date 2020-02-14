#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v1{1,2,3};
    vector<int> v2;

    cout << v1.at(0) << endl;
    cout << v1[0] << endl;
    cout << v1.front() << endl;
    cout << *v1.begin() << endl;

    cout << v2.at(0) << endl;
    cout << v2[0] << endl;
    cout << v2.front() << endl;
    cout << *v2.begin() << endl;
    return 0;
}

