#include "StrVec.h"

#include <string>
using std::string;

#include <iostream>
using std::cout; using std::endl;
using std::istream;

#include <fstream>
using std::ifstream;

void print(const StrVec &svec)
{
    for(string *it = svec.begin(); it != svec.end(); ++it)
        cout << *it << " ";
    cout << endl;
}

StrVec getVec(istream &is)
{
    StrVec svec;
    string s;
    while(is >> s)
        svec.push_back(s);
    return svec;
}

int main(int argc, char const *argv[])
{
    string temp[] = {"one", "two", "three"};
	StrVec sv(temp, temp + sizeof(temp)/sizeof(*temp));

    if (!sv[0].empty()) 
		sv[0] = "None";
    print(sv);

    ifstream in("storyDataFile");
    StrVec svec = getVec(in);
    print(svec);
    in.close();

    cout << "copy " << svec.size() << endl;
    StrVec svec2 = svec;
    print(svec2);
    
    cout << "assign" << endl;
    StrVec svec3;
    svec3 = svec2;
    print(svec2);

    StrVec v1,v2;
    v1 = v2;

    in.open("storyDataFile");
    v2 = getVec(in);
    in.close();
    print(v2);

    StrVec vec;
    string s = "some string or another";
    vec.push_back(s);
    vec.push_back("done");
    print(vec);

    return 0;
}
