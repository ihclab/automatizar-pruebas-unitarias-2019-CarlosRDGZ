#ifndef TESTER_H
#define TESTER_H

#include <string>
#include <vector>

class Tester
{    
private:
    template<typename N>
    static N truncate(N number, int digits = 0);
public:
    template<class F, class P, class O>
    static bool testEqual(F function, P params, O expectedOutput);
};

#endif