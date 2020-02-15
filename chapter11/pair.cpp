#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>


using namespace std;

int main(int argc, const char** argv) 
{
    ifstream in(argv[1]);
    if(!in)
    {
        cout << "文件打开失败" << endl;
        exit(1);
    }
    string str;
    int num;
    vector<pair<string, int>> v1;

    while(in >> str && in >> num)
    {
        v1.push_back((pair<string, int>(str, num)));
    }

    for(auto i : v1)
        cout << i.first << " - " << i.second <<endl;
        
    return 0;
}