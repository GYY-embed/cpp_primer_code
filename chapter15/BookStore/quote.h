#ifndef QUOTE_H
#define QUOTE_H

#include <memory>
#include <iostream>
#include <string>
#include <cstddef>

class Quote
{
public:
    Quote() = default;
    Quote(const std::string &book, double sales_price) : 
        bookNo(book), price(sales_price)    { }
    std::string isbn() const { return bookNo; }
    virtual double net_price(std::size_t n) const
        { return n*price; }
    virtual void debug()
    {
        std::cout << "bookNo = " << bookNo << " price = " << price << std::endl;
    }
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};


class Disc_quote : public Quote
{
public:
    Disc_quote() = default;
    Disc_quote(const std::string &book, double price, std::size_t qty, double disc):
        Quote(book, price), quantity(qty), discount(disc) { }
    double net_price(std::size_t) const = 0;
    std::pair<size_t, double> discount_policy() const
        { return std::make_pair(quantity, discount); }
protected:
    std::size_t quantity = 0;
    double discount = 0.0;
};

class Bulk_quote : public Disc_quote 
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &book, double p, std::size_t qty, double disc):
        Disc_quote(book, p, qty,disc) { }
    double net_price(std::size_t) const ;
/*     virtual void debug()
    {
        Quote::debug();
        std::cout << "min_qty = " << quantity << "discount = " << discount << std::endl;
    } */

};


double print_total(std::ostream &os, const Quote &item, size_t n);
#endif // !QUOTE_H