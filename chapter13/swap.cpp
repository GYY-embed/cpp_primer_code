#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class HasPtr
{
        friend void swap(HasPtr&, HasPtr&);
private:
        int num;
        string *ps;
        std::size_t *use;
public:
        HasPtr() = default;
        HasPtr(const string &s = string()) :
                ps(new string(s)), num(0), use(new std::size_t(1)) {}
        HasPtr(const HasPtr &H) :
                ps(new string (*H.ps)), num(H.num), use(H.use)  { ++*use; }
        HasPtr & operator = (const HasPtr&);
        HasPtr & operator = (const string&);
        HasPtr & operator = (HasPtr);
        bool operator< (const HasPtr&) const;
        string & operator* ();
        ~HasPtr ();
};


inline
void swap(HasPtr &lhs, HasPtr &rhs)
{
        using std::swap;
        swap(lhs.ps,rhs.ps);
        swap(lhs.num, rhs.num);
}

HasPtr::~HasPtr()
{
        if(--*use == 0)
        {
                delete ps;
                delete use;
        }
}

bool HasPtr::operator< (const HasPtr &rhs) const
{
        return *ps < *rhs.ps;
}

inline 
HasPtr & HasPtr::operator = (const HasPtr& rhs)
{
       ++*rhs.use;
       if(--*use == 0)
       {
               delete ps;
               delete use;
       }
       ps = rhs.ps;
       num = rhs.num;
        use = rhs.use;
        return *this;
}

HasPtr &HasPtr::operator = (const string& rhs)
{
        *ps = rhs;
        return *this;
}

HasPtr &HasPtr::operator = (HasPtr rhs)
{
        swap(*this, rhs);
        return *this;
}

string &HasPtr::operator* ()
{
        return *ps;
}

int main(int argc, char const *argv[])
{
        HasPtr h ("hello world");
        HasPtr h2(h);
        HasPtr h3 = h;

        h2 = "hello china";
        h3 = "hello bjc";
        cout << "h : " << *h << endl;
        cout << "h2 : " << *h2 << endl;
        cout << "h3 : " << *h3 << endl;
        swap(h2, h3);
        cout << "h : " << *h << endl;
        cout << "h2 : " << *h2 << endl;
        cout << "h3 : " << *h3 << endl;      

        vector<HasPtr> vh;
        vh.push_back(h);
        vh.push_back(h2);
        vh.push_back(h3);

        sort(vh.begin(), vh.end());
        for(auto i : vh)
                cout << *i << endl;
        
        return 0;
}

