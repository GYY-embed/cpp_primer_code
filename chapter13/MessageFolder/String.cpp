#include <cstring>
using std::strlen;

#include <algorithm>
using std::copy; 

#include <cstddef>
using std::size_t; 

#include <iostream>
using std::ostream; 

#include <utility>
using std::swap;

#include <memory>
using std::uninitialized_copy;

#include "String.h"

//static allocator member
std::allocator<char> String::a;

String &String::operator=(const String &rsh)
{
        char *newp = a.allocate(rsh.sz);
        uninitialized_copy(rsh.p, rsh.p+sz, newp);

        if(p)
                a.deallocate(p, sz);
        p = newp;
        sz = rsh.sz;

        return *this;
}


String &String::operator=(const char *cp)
{
        if(p)
                a.deallocate(p, sz);
        
        p =a.allocate(sz = strlen(cp));
        uninitialized_copy(cp, cp+sz, p);
        
        return *this;
}


String &String::operator=(char c)
{
        if(p)
                a.deallocate(p, sz);
        
        p = a.allocate(sz = 1);\
        *p = c;

        return *this;
}


ostream &print(std::ostream &os, const String &s)
{
        const char *p = s.begin();
        while(p != s.end())
                os << *p++;
        return os;
}


String add(const String &lhs, const String &rhs)
{
        String ret;
        ret.sz = lhs.size()+ rhs.size();
        ret.p = String::a.allocate(ret.sz);
        uninitialized_copy(lhs.begin(), lhs.end(), ret.p);
        uninitialized_copy(rhs.begin(), rhs.end(), ret.p + lhs.sz);
        return ret;
}


String make_plural(size_t ctr, const String &word, const String &ending)
{
        return(ctr !=1 ) ? add(word,ending) : word;
}


ostream &operator<< (std::ostream &os, const String &s)
{
        return print(os, s);
}


String operator+ (const String &lhs, const String &rhs)
{
        return add(lhs, rhs);
}
