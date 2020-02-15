#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <sstream>

using namespace std;

const string &transform(const string &s, const map<string, string> &m);
map<string, string> build_map(ifstream &map_file);
void word_transform(ifstream &map_file, ifstream &input);

int main(int argc, const char** argv) 
{
    if(argc != 3)
    {
        cout << "输入参数不足！" << endl;
        exit(1);
    }
    ifstream map(argv[1]);
    ifstream text(argv[2]);
    word_transform(map, text);
    return 0;
}

map<string, string> build_map(ifstream &map_file)
{
    map<string, string> trans_map;
    string key;
    string value;

    while(map_file >> key && getline(map_file, value))
        if(value.size() > 1)
        {
            trans_map[key] = value.substr(1);
        }    
        else
        {
            throw runtime_error("no rule for " + key);
        }
    return trans_map;
}

const string &transform(const string &s, const map<string, string> &m)
{
    map<string, string>::const_iterator map_it = m.find(s);

    if(map_it != m.end())
    {
        cout << "OK1" << endl;
        cout << map_it->first;
        cout << map_it->second;
        return map_it->second;
    }
    else 
    {
        cout << s;
        return s;
    }    
}

void word_transform(ifstream &map_file, ifstream &input)
{
    auto trans_map = build_map(map_file);
    //for(auto i : trans_map)
        //cout << i.first << "-" << i.second << endl;
    string text;
    while(getline(input, text))
    {
        istringstream stream(text);
        string word;
        bool firstword = true;
        while (stream >> word)
        {
            if(firstword)
                firstword = false;
            else
                cout << " ";
            //cout << word;
            //cout << 
            transform(word, trans_map);
        }
        cout << endl;
    }
}
