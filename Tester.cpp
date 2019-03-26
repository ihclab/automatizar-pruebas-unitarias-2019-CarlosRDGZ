#include <cmath>
#include <string>
#include "Tester.h"

template<typename N>
N truncate(N number, int digits = 0)
{
    if (digits < 0) digits = 0;

    if (digits > 0)
        return trunc(number * pow(10, digits)) / pow(10,digits);
    return trunc(number);
}

template<class F, class P, class O> 
bool Tester::testEqual(F function, P params, O expectedOutput)
{
    try
    {
        return truncate(function(params), 4) == truncate(expectedOutput, 4);
    }
    catch(const std::string e)
    {
        std::string str = std::to_string(expectedOutput);
        return (str.compare("Exception") == 0);
    }
}