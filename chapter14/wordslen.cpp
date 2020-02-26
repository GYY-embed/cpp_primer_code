#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class StrLenIS
{
public:
    StrLenIS(int len) : len(len) { }
    bool operator() (const string &str) { return str.length() == len; }
private:
    int len;
};

void readStr(istream &is, vector<string> &vec)
{
    string word;
    while(is >> word)
        vec.push_back(word);
}
int main(int argc, char const *argv[])
{
    vector<string> vec;
    readStr(cin, vec);
    const int minLen = 1;
    const int maxLen = 10;
    for(int i = minLen; i <= maxLen; i++)
    {
        StrLenIS slenIs(i);
        cout << "Len: " << i << ",cnt : " << count_if(vec.begin(), vec.end(), slenIs) << endl;
    }
    
    return 0;
}
