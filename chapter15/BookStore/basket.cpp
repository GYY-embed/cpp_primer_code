#include "quote.h"
#include "basket.h"

#include <cstddef>
using std::size_t;

#include <set>
using std::multiset; 

#include <string>
using std::string; 

#include <iostream>
using std::ostream; using std::endl; 
using std::cout;

#include <memory>
using std::shared_ptr;

void Basket::display(std::ostream &os) const
{
    os << "Basket size: " << items.size() << endl;

    for(auto next_item = items.begin(); next_item != items.end(); ++next_item)
    {
        os << (*next_item)->isbn() << " occures "
            << items.count(*next_item) << " times "
            << " for a price of "
            << (*next_item)->net_price(items.count(*next_item))
            <<endl;
    }
}

double Basket::total_receipt(std::ostream &os) const
{
    double sum = 0.0;

    for(auto iter = items.begin(); iter != items.end(); ++iter)
    {
        sum += print_total(os, **iter, items.count(*iter));
    }
    os << " Total Sale: " << sum << endl;
    return sum;
}