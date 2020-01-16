#include <iostream>

int main()
{
    int *p1 = nullptr;
    int a = 1;
    int *p2 = &a;

    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    return 0;
}