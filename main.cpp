#include <iostream>
#include <vector>
#include <string>
#include "Tester.h"
#include "TestCaseReader.h"
using namespace std;

int main(int argc, char const *argv[])
{
    vector< vector<string>* >* cases;
    TestCaseReader *reader = new TestCaseReader("CasosPrueba.txt");

    reader->parse();
    cases = reader->getCases();


    for (int i = 0, iLength = cases->size(); i < iLength; i++)
    {
        vector<string>* c = cases->at(i);
        cout << c->at(0) << ": " << Tester::test(c->at(1), split(c->at(2), ' '), c->at(3)) << endl;
    }
    return 0;
}
