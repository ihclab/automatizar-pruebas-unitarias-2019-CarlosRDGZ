#ifndef TESTER_H
#define TESTER_H

#include <string>
#include <vector>

class Tester
{
private:
    static double cast(std::string input);
    static double* cast(std::vector<std::string>* input);
public:
    static bool test(std::string method, std::vector<std::string>* input, std::string output);
};

#endif