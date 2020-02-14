#ifndef __DATE_H
#define __DATE_H

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class date
{
public:
    date = default;
    date(string &ds);

    unsigned y() const { return year; }
    unsigned m() const { return month; }
    unsigned d() const { return day; }
private:
    unsigned year,month,day;
};
const string month_name[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
const string month_abbr[] = {"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sept", "Oct", "Nov", "Dec"};
#endif 