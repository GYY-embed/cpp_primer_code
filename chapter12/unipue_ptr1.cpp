#include <vector>
#include <string>
#include <memory>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
        unique_ptr<int> p1(new int(42));
       // unique_ptr<int> p2 = p1;
        //unique_ptr<int> p2(p1);
        unique_ptr<int> p2;
        p2.reset(p1.release());
       // cout << "p1 : " << *p1 << endl;
        cout << "p2 : " << *p2 << endl;
        return 0;
}
