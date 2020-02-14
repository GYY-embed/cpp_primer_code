#include <iostream>
#include <string>

using namespace std;

void replace1(string &s, const string &oldval, const string &newval)
{
    auto l = oldval.size();
    if(!l)
        return;
    auto it = s.begin();
    while(it <= s.end()-1)
    {
        //cout << *it << endl;
        auto iter1 = it;
        auto iter2 = oldval.begin();
        while (iter2 != oldval.end() && *iter1 == *iter2)
        {
            iter1++;
            iter2++;
        }
        if(iter2 == oldval.end())//get
        {
            it = s.erase(it, iter1);
            if(newval.size())
            {
                iter2 = newval.end();
                do
                {
                    iter2--;
                    it = s.insert(it, *iter2);
                } while (iter2 > newval.begin());   
            }
            it += newval.size();
        }  
        else
            it++;
    }
}

void replace2(string &s, const string &oldval, const string &newval)
{
    int p = 0;
    while((p = s.find(oldval, p)) != string ::npos)
    {
        s.replace(p, oldval.size(), newval);
        p += newval.size();
    }
}
int main(int argc, const char** argv) 
{
    string s = "the thru tho";
    replace1(s, "thru", "through");
    cout << s << endl;

    replace1(s, "tho", "though");
    cout << s << endl;
       
    replace1(s, "through", "   ");
    cout << s << endl;

    string s1 = "the thru tho";
    replace2(s1, "thru", "through");
    cout << s1 << endl;

    replace2(s1, "tho", "though");
    cout << s1 << endl;
       
    replace2(s1, "through", "   ");
    cout << s1 << endl;
    return 0;
}