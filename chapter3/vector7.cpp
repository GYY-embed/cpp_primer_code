//3.25
#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<unsigned> scores(11,0);
    unsigned grade;
    while(cin >> grade)
    {
        if(grade <= 100)
            (*(scores.begin()+(grade/10)))++;
    }
    for(auto it = scores.begin(); it != scores.end(); ++it)
        cout << *it << " ";
    cout << endl;    
    return 0;
}