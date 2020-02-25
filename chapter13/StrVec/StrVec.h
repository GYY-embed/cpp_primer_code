#ifndef STRVEC_H
#define STRVEC_H

#include <iostream>
#include <memory>
#include <utility>
//#include <string>

class StrVec
{
public:
    StrVec():
        elements(0), first_free(0), cap(0) { }

    StrVec(const StrVec &);
    StrVec &operator=(const StrVec &);
    
    ~StrVec();
    
    StrVec(const std::string *, const std::string *);
    void push_back(const std::string &);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }

    std::string *begin() const { return elements; }
    std::string *end() const { return first_free; }

    std::string &operator[](std::size_t n)
        { return elements[n]; }
    const std::string &operator[](std::size_t n) const
        { return elements[n]; } 
private:
    static std::allocator<std::string> alloc;
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    std::pair<std::string*, std::string*> alloc_n_copy
        (const std::string*, const std::string*);
    void free();//销毁数据并释放内存
    void reallocate();//获取更多的空间
    std::string *elements;//指向数组中的第一个元素
    std::string *first_free;//指向第一个空闲内存（尾后）
    std::string *cap;//指向数组的尾后（可用空间的尾后）
};

#include <algorithm>

inline
StrVec::~StrVec() { free(); }

inline
std::pair<std::string*, std::string*> 
StrVec::alloc_n_copy(const std::string *b, const std::string *e)
{
    std::string *data = alloc.allocate(e - b);

    return std::make_pair(data, uninitialized_copy(b, e, data));
}


inline
StrVec::StrVec(const StrVec &s)
{
	std::pair<std::string*, std::string*> newdata = 
							alloc_n_copy(s.begin(), s.end());
	elements = newdata.first; 
	first_free = cap = newdata.second;
}

inline
void StrVec::free()
{
    if(elements)
    {
        for(std::string *p = first_free; p != elements; )
            alloc.destroy(--p); 
        alloc.deallocate(elements, cap - elements);
    }
}
inline
StrVec &StrVec::operator=(const StrVec &rhs)
{
    std::pair<std::string*, std::string*> data = 
                                alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;

    return *this;
}

inline
void StrVec::reallocate()
{
    size_t newcapacity = size() ? 2*size() : 1;

    std::string *newdata = alloc.allocate(newcapacity);

    std::string *dest = newdata;
    std::string *elem = elements;
    for(size_t i = 0; i != size(); ++i)
        alloc.construct(dest++, *elem++);
    
    free();

    elements = newdata;
    first_free = dest;
    cap = elements + newcapacity;
}

inline
StrVec::StrVec(const std::string * b, const std::string * e)
{
    std::pair<std::string*, std::string*> newdata = alloc_n_copy(b, e);
    elements = newdata.first;
    first_free = cap = newdata.second;
}

inline
void StrVec::push_back(const std::string &s)
{
    chk_n_alloc();
    alloc.construct(first_free++, s);
}


#endif // !STRVEC_H
