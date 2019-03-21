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
    regex isVector("\\s+");
    vector< vector<string>* >* test = reader->getTests();
    
    cout << (regex_match(" a", isVector) ? "true" : "false") << endl << endl;
    return 0;
    
    for(int i = 0; i < test->size(); i++)
    {
        for(int j = 0; j < test->at(i)->size(); j++)
        {
            string str = test->at(i)->at(j);
            cout << str << " ";
            cout << ((regex_match(str, isString) == true) ? "string" : (regex_match(str, isVector) ? "vector" : "number")) << endl;
        }
        cout << endl;
    }

    delete reader;
    delete test;

    return 0;
}
