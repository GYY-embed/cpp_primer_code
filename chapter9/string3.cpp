#include <iostream>
#include <string>
#include <vector>

using namespace std;

int add_vector1(vector<string> &v1)
{
    int sum = 0;
    for(auto i : v1)
        sum += stoi(i);
    return sum;
}

float add_vector(vector<string> &v1)
{
    float sum = 0;
    for(auto i : v1)
        sum += stod(i);
    return sum;
}


int main()
{
    vector<string> v1{"1", "2", "3", "46", "5", "6"};
    vector<string> v2{"1.3", "2.5", "3.7", "46.1", "5.0", "6.8"};
    cout << add_vector1(v1) << endl;
    cout << add_vector(v2) << endl;
    return 0;
}