#include <cmath>
#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <Windows.h>
#include "Medias.h"
#include "MethodsMedias.h"
#include "Tester.1.h"
#include "TestCaseReader.h"
using namespace std;

double cast(string input);
vector<double>* cast(vector<string>* input);
void printTestResult(string id, bool result, int &var);
void printResume(int passed, int failed, int total);

int main()
{
    bool result;
    int passed = 0, failed = 0;
    regex isString("[a-zA-Z]+");
    vector< vector<string>* >* cases;
    TestCaseReader *reader = new TestCaseReader("CasosPrueba.txt");

    reader->parse();
    cases = reader->getCases();

    for (int i = 0, iLength = cases->size(); i < iLength; i++)
    {
        vector<string>* c = cases->at(i);
        try
        {
            if (MethodsMedias::MEDIA_ARITMETICA.compare(c->at(1)) == 0)
                result = Tester::testEqual(Medias::mediaAritmetica, cast(split(c->at(2), ' ')), cast(c->at(3)));
            else if (MethodsMedias::MEDIA_ARMONICA.compare(c->at(1)) == 0)
                result = Tester::testEqual(Medias::mediaArmonica, cast(split(c->at(2), ' ')), cast(c->at(3)));
            else if (MethodsMedias::MEDIA_GEOMETRICA.compare(c->at(1)) == 0)
               result = Tester::testEqual((new Medias())->mediaAritmetica, cast(split(c->at(2), ' ')), cast(c->at(3)));
            else
            {
                if (c->at(3).compare("Exception"))
                    printTestResult(c->at(0), true, passed);
                else
                    printTestResult(c->at(0), false, failed);
                continue;
            }
            printTestResult(c->at(0), result, (result ? passed : failed));
        }
        catch (const string ex)
        {
            if (ex.compare("Exception") == 0)
                printTestResult(c->at(0), true, passed);
            else
                printTestResult(c->at(0), false, failed);
        }
    }
    printResume(passed, failed, cases->size());
    return 0;
}

double cast(string input)
{
    try
    {
        return stod(input);
    }
    catch(const std::invalid_argument ex)
    {
        throw input;
    }
}

vector<double>* cast(vector<string>* input)
{
    if (input == NULL)
        return NULL;
    
    vector<double>* values = new vector<double>(); 
    try
    {
        for(int i = 0; i < input->size(); i++)
            values->push_back(cast(input->at(i)));
    }
    catch (const string ex)
    {
        throw ex;
    }

    return values;
}

void printTestResult(string id, bool result, int &var)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    if (result)
        SetConsoleTextAttribute(color, 10); // Green
    else
        SetConsoleTextAttribute(color, 12); // Red
    
    cout << id << ": " << (result ? "Success" : "Fail") << endl;
    var++;
}

void printResume(int passed, int failed, int total)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 7);
    cout << "\nTotal Test: " << total << ". " << "Passed: " << passed << ". " << "Failed: " << failed << "." << endl;
}