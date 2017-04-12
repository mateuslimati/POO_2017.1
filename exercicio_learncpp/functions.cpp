#include <iostream>
#include "myheader.h"

using namespace std;

int mull_div(int x, int y)
{

#ifdef PRINT
    return x / y;
#endif
#ifndef PRINT
    return x * y;
#endif
}

int add(int x, int y, int z)
{
    return x + y + z;
}

int doubleNumber(){

    int x;
    cin >> x;
    x = x * 2;
    return x;

}
