#ifndef PERSON_DATA_H
#define PERSON_DATA_H

#include <string>
#include <iostream>


class Person_data {
public:
    Person_data() = default;
    Person_data(std::istream &);
    Person_data(const std::string &s1, const std::string &s2, unsigned a):
        strName(s1), strAddress(s2), uAge(a) { }
    Person_data(const std::string &s1): 
         strName(s1) { }
	// operations on Person_data objects
	std::string get_name() const { return strName; }
    std::string get_address() const { return strAddress; }
    unsigned int get_age() const { return uAge;}
//private:
	std::string strName;
	std::string strAddress;
    unsigned uAge = 0;
};


// nonmember Person_data interface functions
std::ostream &print(std::ostream&, const Person_data&);
std::istream &read(std::istream&, Person_data&);



#endif