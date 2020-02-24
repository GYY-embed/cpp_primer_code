#include <iostream>
#include <string>

using namespace std;

class employee
{
private:
        static int seq;
public:
        employee() { number = seq ++; }
        employee(const string &s) { number = seq++, name = s; } 

        //拷贝控制成员
        employee(employee &e) { name = e.name; number = seq++; }
        employee& operator= (employee &rhs) { name = rhs.name; return *this; }

        const string &get_name() {return name; }
        int get_num()  {return number; }
private:
        int number;
        string name;
};