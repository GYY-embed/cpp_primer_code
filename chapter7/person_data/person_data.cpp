#include <iostream>
using std::istream; using std::ostream;

#include "person_data.h"

Person_data::Person_data(std::istream &is)
{
    read(is,*this);
}

istream&
read(istream &is, Person_data &item)
{
	is >> item.strName >> item.strAddress >> item.uAge;
	return is;
}

ostream&
print(std::ostream &os, const Person_data &item)
{
	os << item.get_name() << " " << item.get_address() << " " << item.get_age() << " ";
	return os;
}