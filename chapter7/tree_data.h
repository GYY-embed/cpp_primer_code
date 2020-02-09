#ifndef TREE_DATA_H
#define TREE_DATA_H

#include <string>
#include <iostream>

class Tree
{
public:
    Tree() = default;
    Tree(const std::string &n, unsigned a, double h) : 
        name(n), age(a), height(h) { }
    Tree(const std::string &n = ""):name(n) { }

private:
    std::string name;
    unsigned age = 0;
    double height = 0;
};


#endif