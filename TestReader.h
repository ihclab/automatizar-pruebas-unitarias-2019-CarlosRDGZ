#ifndef TEST_READER_H
#define TEST_READER_H

#include <string>
#include <vector>
#include <fstream>

class TestReader
{
private:
    std::string filePath;
    std::ifstream* file;
    std::vector< std::vector<std::string>* >* tests;
public:
    TestReader(std::string path);
    ~TestReader();
    void parse();
    std::vector< std::vector<std::string>* >* getTests() const;
};

#endif