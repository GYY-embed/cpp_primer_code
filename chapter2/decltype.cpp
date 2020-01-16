#include <iostream>


int main()
{
    int a = 3, b = 4;
    decltype(a) c = a;
    decltype((b)) d = a;
    ++c;
    ++d;
    std::cout << " a: " << a << " c: " << c << " d: " << d << std::endl;
    return 0;
}