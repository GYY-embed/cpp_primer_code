#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
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
        string & operator* ();
        ~HasPtr ();
};

HasPtr::~HasPtr()
{
        if(--*use == 0)
        {
                delete ps;
                delete use;
        }
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
        h2 = "hello bjc";
        cout << "h : " << *h << endl;
        cout << "h2 : " << *h2 << endl;
        cout << "h3 : " << *h3 << endl;
        return 0;
}

