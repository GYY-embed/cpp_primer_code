#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

int main()
{
    int num1, num2;
    cout << "Please input num1 and num2 : ";
    while(cin >> num1 >> num2)
    {
        try 
        {
            if(num2 == 0)
            {
                throw runtime_error("Divisor cannot be zero");
            }
            cout << "result: " << num1/num2 << endl;
        }
        catch(runtime_error err)
        {
            cout << err.what() << endl;
            cout << "Continue (y or n) ?";
            char ch;
            cin >> ch;
            if(ch != 'y' && ch != 'Y')
                break;
        }
    }
    return 0;
}