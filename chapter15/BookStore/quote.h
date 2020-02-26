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
    virtual ~Quote() = default;
private:
    std::string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote : public Quote 
{
public:
    Bulk_quote() = default;
    Bulk_quote(const std::string &, double, std::size_t, double);
    double net_price(std::size_t) const override;
private:
    std::size_t min_qty = 0;//适用折扣政策的最低购买量
    double discount = 0.0;//折扣额，小数
};

#endif // !QUOTE_H