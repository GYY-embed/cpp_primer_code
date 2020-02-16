#include <vector>
#include <string>
#include <memory>
#include <stdexcept>
#include <iostream>

using namespace std;

vector<int>* create()
{
    auto l1 = new vector<int> ;
    return l1;
}

void input(vector<int>* l1)
{
    int num;
    while(cin >>num)
        l1->push_back(num);
}

void print_data(vector<int>* l1)
{
    for(const auto &v : *l1)
        cout << v << " ";
    cout << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> *pv = create();
    if(!pv)
    {
        cout << "内存不足" <<endl;
        return -1;
    }

    input(pv);
    print_data(pv);

    delete pv;
    pv = nullptr;
    
    return 0;
}
