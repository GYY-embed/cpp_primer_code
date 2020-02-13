#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <stdexcept>

using namespace std;

int main()
{
    ifstream in("data");
    if(!in)
    {
        cout << "文件打开失败" <<endl;
        return -1;
    }
    string line;
    vector<string> words;
    while(getline(in, line))
    {
        words.push_back(line);
    }
    in.close();

    vector<string>::const_iterator it = words.begin();
    while(it != words.end())
    {
        istringstream line_str(*it);
        string word;
        while(line_str >> word)
            cout << word << " ";
        cout << endl;
        ++it;
    }
    return 0;
}