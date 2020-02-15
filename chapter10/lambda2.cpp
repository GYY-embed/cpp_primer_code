#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

void elimDups(vector<string> &words)
{
    sort(words.begin(), words.end());
    auto end_unique = unique(words.begin(), words.end());
    words.erase(end_unique, words.end());
}

string make_plural(size_t ctr,const string &word, const string &ending)
{
  return (ctr==1) ? word : word+ending;
}
void biggies1(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                    { return a.size() < b.size(); });
    auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" <<endl;
    for_each(wc, words.end(), 
            [](const string &s)
                { cout<< s << " "; });
    cout << endl;
}   

void biggies2(vector<string> &words, vector<string>::size_type sz)
{
    elimDups(words);
    for(auto i : words)
        cout << i << " ";
    cout << endl;
     stable_sort(words.begin(), words.end(),
                [](const string &a, const string &b)
                    { return a.size() < b.size(); });
    for(auto i : words)
        cout << i << " ";
    cout << endl;
/*     auto wc = find_if(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() >= sz; }); */
    for(auto i : words)
        cout << i << " ";
    cout << endl;
    auto wc = stable_partition(words.begin(), words.end(),
                [sz](const string &a)
                    { return a.size() < sz; });
    auto count = words.end() - wc;
    cout << count << " " << make_plural(count, "word", "s")
        << " of length " << sz << " or longer" <<endl;
    for_each(wc, words.end(), 
            [](const string &s)
                { cout<< s << " "; });
    cout << endl;
}   

int main(int argc, const char** argv) 
{
    vector<string> v1{"hello", "world", "gyy", "hello", "c++", "2020", "world", "vc", "wcg", "amd", "intel"};
    biggies2(v1, 4);
    return 0;
}