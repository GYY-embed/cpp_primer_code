#include "myfact.h"

int fact(int num)
{
    int retval = 1;
    for(int i = 1; i <= num ; ++i)
        retval *= i;
    return retval;
}