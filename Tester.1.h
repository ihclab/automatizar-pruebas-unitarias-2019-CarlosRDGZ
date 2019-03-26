#ifndef TESTER_H
#define TESTER_H

#include <iostream>
#include <cmath>
#include <string>
#include <vector>

class Tester
{    
private:
    template<typename N>
    static N truncate(N number, int digits = 0)
    {
        if (digits < 0) digits = 0;

        if (digits > 0)
            return trunc(number * pow(10, digits)) / pow(10,digits);
        return trunc(number);
    }

public:
    template<class F, class P, class O>
    static bool testEqual(F function, P params, O expectedOutput)
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
};

#endif