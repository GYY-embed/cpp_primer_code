#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(int argc, const char** argv) 
{
    vector<string> v1{"hello", "world", "gyy", "hello", "c++", "2020", "world", "vc", "wcg", "amd", "intel"};
    cout << "There are " << count_if(v1.begin(), v1.end(), 
                [](const string &s)
                    { return s.size() >= 4; }) << " words" << endl;

    return 0;
}