#include <sstream>
#include <fstream>
#include <istream>
#include "TestCaseReader.h"

TestCaseReader::TestCaseReader(std::string path)
{
    this->file = NULL;
    this->filePath = path;
    this->cases = NULL;
}

TestCaseReader::~TestCaseReader()
{
    delete this->file;
    delete this->cases;
}

void TestCaseReader::parse()
{
    if (NULL == this->file)
    {
        this->file = new std::ifstream(this->filePath);
        this->cases = new std::vector<std::vector<std::string>*>();

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
                this->cases->push_back(line);
            }
            
            this->file->close();
        }
        this->file->close();
    }
}

std::vector< std::vector<std::string>* >* TestCaseReader::getCases() const { return this->cases; }

std::vector<std::string>* split(std::istream& stream, char delim = '\n')
{
    std::string str = "";
    std::vector<std::string>* lines = new std::vector<std::string>();

    while(std::getline(stream, str, delim))
    {
        lines->push_back(str);
    }

    return lines;
}

std::vector<std::string>* split(std::string str, char delim = '\n')
{
    std::stringstream ss(str);
    return split(ss, delim);
}