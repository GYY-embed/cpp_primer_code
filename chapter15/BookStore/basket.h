#ifndef BASKET_H
#define BASKET_H

#include <iostream>
#include <string>
#include <set>
#include <map>
#include <utility>
#include <cstddef>
#include <stdexcept>
#include <memory>
#include "quote.h"

class Basket
{
public:
    Basket(): items(compare) { }
    void add_item(const std::shared_ptr<Quote> &sale)
        { items.insert(sale); }
    void add_item(const Quote &sale)
        { items.insert(std::shared_ptr<Quote>(sale.clone())); }
    double total_receipt(std::ostream &) const;
    void display(std::ostream &) const;

private:
    static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs)
        { return lhs->isbn() < rhs ->isbn(); }
    typedef bool(*Comp) (const std::shared_ptr<Quote> &, const std::shared_ptr<Quote> &);
    std::multiset<std::shared_ptr<Quote>, Comp> items;
};

#endif