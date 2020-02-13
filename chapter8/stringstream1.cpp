#include <sstream>
#include <stdexcept>
#include <iostream>
#include <string>

using namespace std;

istream & f(istream &in)
{
    string v;
    while(in >> v, !in.eof())
    {
        if(in.bad())
            throw runtime_error("IO流错误");
        if(in.fail())
        {
            cerr << "数据错误，请重试 ： " << endl;
            in.clear();
            in.ignore(100, '\n');
            continue;
        }
        cout << v << endl;
    }
    in.clear();
    return in;
}

int main()
{
    ostringstream msg;
    msg << "C++ Primer no.5" << endl;
    istringstream in(msg.str());
    f(in);
    return 0;
}