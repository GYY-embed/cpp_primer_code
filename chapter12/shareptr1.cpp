#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

shared_ptr<vector<int>> create()
{
    return make_shared<vector<int>>();
}

void input(shared_ptr<vector<int>> l1)
{
    int num;
    while(cin >>num)
        l1->push_back(num);
}

void print_data(shared_ptr<vector<int>> l1)
{
    for(const auto &v : *l1)
        cout << v << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    auto pv = create();
    input(pv);
    print_data(pv);
    
    return 0;
}
