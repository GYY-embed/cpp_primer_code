#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

using int_array = int[4];

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    for(int_array *p = ia; p != ia+3; ++p)
    {
        for(int *q = *p; q != *p+4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    return 0;
}