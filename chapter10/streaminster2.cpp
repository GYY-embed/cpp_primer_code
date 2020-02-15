#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <iterator>


using namespace std;

int main(int argc, const char** argv) 
{
    vector<string> v1;
    istream_iterator<string> in_iter(cin);
    istream_iterator<string> eof;

    ostream_iterator<string> out_iter(cout, " ");

    while(in_iter != eof)
        v1.push_back(*in_iter++);

    sort(v1.begin(), v1.end());

    copy(v1.begin(), v1.end(), out_iter);
    cout << endl;
    return 0;
}