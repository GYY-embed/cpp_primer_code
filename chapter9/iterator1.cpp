#include <iostream>
#include <vector>

using namespace std;

bool search1(vector<int>::const_iterator beg, vector<int>::const_iterator end, int data)
{
    while(beg != end)
    {
        cout << *beg << endl;
        if(*beg == data)
            return true;
        ++beg;
    }
    return false;
}

vector<int>::const_iterator search2(vector<int>::const_iterator beg, vector<int>::const_iterator end, int data)
{
    while(beg != end)
    {
        //cout << *beg << endl;
        if(*beg == data)
            return beg;
        ++beg;
    }
    return end;
}

int main()
{
    vector<int> v1{1, 3, 5, 7, 9, 11, 13};
    vector<int>::const_iterator beg = v1.begin();
    vector<int>::const_iterator end = v1.end();
    search1(beg, end, 7)? (cout << "can find '7' " << endl):(cout << "can't find '7'" << endl);

    cout << search2(beg, end, 7) - beg << endl;
    cout << search2(beg, end, 5) - beg << endl;
    
    return 0;
}