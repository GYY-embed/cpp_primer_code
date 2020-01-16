#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    int ia[3][4] = {
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11}
    };
    //type 1
    cout << "Type 1: " << endl;
    for(auto &row : ia)
    {
        for(auto &col : row)
            cout << col << " ";
        cout << endl;
    }        
    cout << endl;
    //type 2
    cout << "Type 2: " << endl;
    size_t row_num = 3;
    size_t col_num = 4;
    for(size_t i = 0; i < row_num; i++)
    {
        for(size_t j = 0; j < col_num; j++)
            cout << ia[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    //type 3
    cout << "Type 3: " << endl;
    for(auto p = ia; p != ia+3; ++p)
    {
        for(auto q = *p; q != *p+4; ++q)
            cout << *q << " ";
        cout << endl;
    }
    cout << endl;
    return 0;
}