#ifndef TEST_CASE_READER_H
#define TEST_CASE_READER_H

#include <string>
#include <vector>
#include <fstream>

class TestCaseReader
{
private:
    std::string filePath;
    std::ifstream* file;
    std::vector< std::vector<std::string>* >* cases;
public:
    TestCaseReader(std::string path);
    ~TestCaseReader();
    void parse();
    std::vector< std::vector<std::string>* >* getCases() const;
};

std::vector<std::string>* split(std::istream& stream, char delim /* = '\n' */);
std::vector<std::string>* split(std::string str, char delim /* = '\n' */);

#endif