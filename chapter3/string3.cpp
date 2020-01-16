#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    string sum,s_temp;
    int i=0;
    std::cout << "Please input strings" << std::endl;
    while(getline(cin,s_temp))
    {
        i++;
        if(i==1)
             sum += s_temp;
        else
            sum += " " + s_temp;
    }
    cout << sum << endl; 
    return 0;
}