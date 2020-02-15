#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s, string::size_type sz)
{
    return s.size() <= sz;
}

void biggies(vector<int> &v1, const string &s)
{
    auto p = find_if(v1.begin(), v1.end(),
                bind(check_size, s, _1));
    cout << "第" << p-v1.begin()+1 << "个数" << *p
        << "大于等于" << s << "的长度" << endl;
}

int main(int argc, const char** argv) 
{
    vector<int> v1{1, 2, 3, 4, 5, 6, 7, 8};
    biggies(v1, "Hello");
    biggies(v1, "GYY");
    biggies(v1, "everyone");
    return 0;
}