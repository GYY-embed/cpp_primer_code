#include <iostream>

int main()
{
    int i =0, &r1 = i;
    double d = 0, &r2 = d;
    std::cout << i << r1 << d << r2 << std::endl;
    
    r2 = 3.14;
    r2 = r1;
    i = r2;
    r1 = d;

    std::cout << i << r1 << d << r2 << std::endl;  
}