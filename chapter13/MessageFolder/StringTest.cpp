#include <iostream>
#include "String.h"

using namespace std;
int main(int argc, char const *argv[])
{
        String s1 = "hello", s2 = s1, s3(5, 'g'), s4;
        cout << "S1 : " << s1 << endl;
        cout << "S2 : " << s2 << endl;
        cout << "S3 : " << s3 << endl;
        cout << "S4 : " << s4 << endl;
        s4 = 's';
        cout << "S4 : " << s4 << endl;
        s2.swap(s3);
        cout << "S2 : " << s2 << endl;
        cout << "S3 : " << s3 << endl;
        for(auto i = s1.begin(); i!= s1.end(); ++i)
                cout << i << endl;
        String s5 = s1+ s3;
        cout << "S5 : " << s5 << endl;
               

        return 0;
}
