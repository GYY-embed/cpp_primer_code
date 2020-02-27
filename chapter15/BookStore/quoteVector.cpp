#include <iostream>
#include <string>
#include <ostream>
#include <vector>
#include "quote.h"
#include <memory>

using namespace std;

int main(int argc, char const *argv[])
{
    vector<Quote> itemVec;
    for(size_t i = 0; i != 10; ++i)
    {
        Bulk_quote item("C++ Primer",6, 5, 0.5);
        itemVec.push_back(item);
    }
    double sum = 0;
    for(auto iter = itemVec.begin(); iter != itemVec.end(); ++iter)
    {
        sum += iter->net_price(10);
    }

    cout << "SUM1 : " << sum << endl;

    vector<shared_ptr<Quote>> itemVec2;
    for(size_t i = 0; i != 10; ++i)
    {
        Bulk_quote item("C++ Primer",6, 5, 0.5);
        itemVec2.push_back(make_shared<Bulk_quote>(item));
    }
    double sum2 = 0;
    for(auto iter = itemVec2.begin(); iter != itemVec2.end(); ++iter)
    {
        sum2 += (*iter)->net_price(10);
    }

    cout << "SUM2 : " << sum2 << endl;

    return 0;
}
