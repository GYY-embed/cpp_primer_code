#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, const char** argv) 
{
    int num, numTofind;
    vector<int> v1;
    cout << "请输入整数序列： " << endl;
    while(cin >> num)
    {
       // cout << num << endl;
        v1.push_back(num);
    }
    cin.clear();
    clearerr(stdin);
    for(auto i : v1)
    {
        cout << i << " ";             
    }
    cout << endl;
    
    cout << "请输入一个要查询的数： ";
    cin >> numTofind
    cout << "出线次数： " << count(v1.cbegin(), v1.cend(), numTofind) << endl;
    return 0;
}