#include <iostream>
#include <string>

using namespace std;

void print()
{
    cout << "func 1" << endl;
    cout << "Hello World" << endl;
}

void print(int a)
{
    cout << "func 2" << endl;
    cout << "Data : " << a << endl;
}

void print(int a, int b)
{
    cout << "func 3" << endl;
    cout << "Data : " << a << " " << b <<endl;
}
void print(float a, float b = 4.6)
{
    cout << "func 4" << endl;
    cout << "Data : " << a << " " << b <<endl;
}

int main()
{
    print();
    print(3);
    //print(3.6); //error
    print(3,9);
    //print(3.6, 4.6); //error
    return 0;
}