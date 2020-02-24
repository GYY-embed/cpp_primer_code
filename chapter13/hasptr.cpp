#include <iostream>
#include <string>

using namespace std;

class HasPtr
{
private:
        int num;
        string *ps;
public:
        HasPtr() = default;
        HasPtr(const string &s = string()) :
                ps(new string(s)), num(0) {}
        HasPtr(HasPtr &H) :
                ps(new string (*H.ps)), num(H.num) { }
        HasPtr & operator = (const HasPtr&);
        HasPtr & operator = (const string&);
        string & operator* ();
        ~HasPtr ();
};

HasPtr::~HasPtr()
{
        delete ps;
}

inline 
HasPtr & HasPtr::operator = (const HasPtr& rhs)
{
        auto newps = new string (*rhs.ps);
        delete ps;
        ps = newps;
        num = rhs.num;
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

