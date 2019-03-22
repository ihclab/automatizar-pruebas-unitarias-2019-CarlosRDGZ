#include <sstream>
#include <fstream>
#include "TestReader.h"

TestReader::TestReader(std::string path)
{
    this->file = NULL;
    this->filePath = path;
    this->tests = NULL;
}

TestReader::~TestReader()
{
    delete this->file;
    delete this->tests;
}

void TestReader::parse()
{
    if (NULL == this->file)
    {
        this->file = new std::ifstream(this->filePath);
        this->tests = new std::vector<std::vector<std::string>*>();

        if (this->file->is_open())
        {
            std::string str = "";
            std::vector<std::string>* line;

            while(std::getline(*this->file, str))
            {
                std::string s;
                std::stringstream stream(str);
                line = new std::vector<std::string>();
                while(std::getline(stream, s, ':')) { line->push_back(s); }
                this->tests->push_back(line);
            }
            
            this->file->close();
        }
        this->file->close();
    }
}

std::vector< std::vector<std::string>* >* TestReader::getTests() const { return this->tests; }