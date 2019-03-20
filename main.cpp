#include <iostream>
#include <vector>
#include <string>
#include "Medias.h"
#include "TestReader.h"
using namespace std;

int main(int argc, char const *argv[])
{
    TestReader *reader = new TestReader("CasosPrueba.txt");
    reader->parse();
    vector< vector<string>* >* test = reader->getTests();
    
    for(int i = 0; i < test->size(); i++)
    {
        for(int j = 0; j < test->at(i)->size(); j++)
            cout << test->at(i)->at(j) << " ";
        cout << endl;
    }

    delete reader;
    delete test;

    return 0;
}
