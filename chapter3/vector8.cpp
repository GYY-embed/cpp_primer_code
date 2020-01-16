#include <vector>
#include <iostream>

using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::vector;

int main()
{
    vector<int> v1{1,2,3,4,5,6,7,8,9,10,11,12};
    auto beg = v1.begin(), end = v1.end();
    auto mid = beg + (end - beg)/2;
    int num;
    cout << "Please input a num : " ;
    cin >> num;
    if(num > *(v1.end()-1))
        cout << "Don't have this num! " << endl;
    else
    {
        while(mid != end && *mid != num)
        {
            if(num < *mid)
                end = mid;
            else
                beg = mid+1;
            mid = beg + (end - beg)/2;
        }

    }
    if(*mid == num)
        cout << "Find! "<< endl << "at :"  <<  mid - v1.begin() + 1 << endl ;
    return 0;
}