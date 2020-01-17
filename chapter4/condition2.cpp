#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    unsigned grade;
    string finalgrade;
    cout << "Please input grade : " ;
    cin >> grade;
    finalgrade = (grade >= 90) ? "high pass" : (grade >= 75) ? "pass" : (grade >= 60) ? "low pass" : "fail";
    cout << "finalgrade : " << finalgrade << endl;
    return 0;
}