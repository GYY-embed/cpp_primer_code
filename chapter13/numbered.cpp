#include <iostream>

using namespace std;

class numbered
{
private:
        static int num;
public:
        numbered( ) { mysn =num++; }
        numbered (numbered &) { mysn = num ++; }
        int mysn;
};

int numbered::num = 0;

void f(const numbered &s)
//void f(numbered s)
{
        cout << s.mysn <<endl;
}
int main(int argc, char const *argv[])
{
        numbered a, b = a, c = b;
        f(a), f(b), f(c); 
        return 0;
}
