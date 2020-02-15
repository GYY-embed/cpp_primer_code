#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <iterator>


using namespace std;

int main(int argc, const char** argv) 
{
    fstream in(argv[1]);
    if(!in)
    {
        cout << "打开输入文件失败！" << endl;
        exit(1);
    }
    istream_iterator<string> in_iter(in);
    istream_iterator<string> eof;
    vector<string> words;

    while(in_iter != eof)
        words.push_back(*in_iter++);
    
    for(auto i : words)
        cout << i << " ";
    cout << endl;
    return 0;
}