#include <iostream>
#include <vector>
#include <string>
#include <regex>
#include "Medias.h"
#include "TestReader.h"
using namespace std;

int main(int argc, char const *argv[])
{
    TestReader *reader = new TestReader("CasosPrueba.txt");
    reader->parse();

    regex isString("[a-zA-Z]+");
    vector< vector<string>* >* tests = reader->getTests();
    for(int i = 0, iLength = tests->size(); i < iLength; i++)
    {
        vector<string>* test = tests->at(i);
        for(int j = 0, jLength = test->size(); j < jLength; j++)
        {
            string str = test->at(j);
            cout << str << " ";
            cout << (
                (regex_match(str, isString) == true) ? 
                    "string" : 
                    (str.find(' ') != string::npos ? "vector" : "number"))
                << endl;
        }
        cout << endl;
    }

    delete reader;
    delete tests;

    return 0;
}
