#include <iostream>
#include <fstream>
#include "Sales_data.h"

using namespace std;

int main(int argc, char *argv[])
{
    if(argc != 3)
    {
        cerr << "请给出输入、输出文件名" <<endl;
        return -1;
    }
    ifstream in(argv[1]);
    if(!in)
    {
        cerr << "无法打开输入文件" << endl;
        return -1;
    }
    //ofstream out(argv[2]);
    ofstream out(argv[2], ofstream::app);
    if(!out)
    {
        cerr << "无法打开输出文件" << endl;
        return -1;        
    }
    //cout << "请输入交易记录（ISBN、销售量、原价、实际售价）: " << endl;
    Sales_data total;
    out << sizeof(total) << endl;
    if(read(in, total))
    {
        Sales_data trans;
        while(read(in, trans))
        {
            if(total.isbn() == trans.isbn())
                total.combine(trans);
            else
            {
                print(out, total) << endl;
                total = trans;
            }
        }
        print(out, total) << endl;
    }
    else
    {
        cerr << "No data?!" << endl;
        return -1;
    }
    return 0;
}
