#include <cmath>
#include <chrono>
#include <fstream>
#include <iomanip>
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
void printResume(int passed, int failed, int total, ofstream &file);
void printTestResult(string id, bool result, double elapsedTime, ofstream &file, int &var);
template<class F>
bool callTest(F function, string params, string result, double &elapsedTime);

ofstream resultFile;

int main()
{
    bool result;
    int passed = 0, failed = 0;
    regex isString("[a-zA-Z]+");
    vector< vector<string>* >* cases;
    TestCaseReader *reader = new TestCaseReader("CasosPrueba.txt");

    reader->parse();
    cases = reader->getCases();
    resultFile.open("Result.txt");

    for (int i = 0, iLength = cases->size(); i < iLength; i++)
    {
        double elapsedTime = 0.0;
        vector<string>* c = cases->at(i);
        try
        {
            if (MethodsMedias::MEDIA_ARITMETICA.compare(c->at(1)) == 0)
                result = callTest(Medias::mediaAritmetica, c->at(2), c->at(3), elapsedTime);
            else if (MethodsMedias::MEDIA_ARMONICA.compare(c->at(1)) == 0)
                result = callTest(Medias::mediaArmonica, c->at(2), c->at(3), elapsedTime);
            else if (MethodsMedias::MEDIA_GEOMETRICA.compare(c->at(1)) == 0)
                result = callTest((new Medias())->mediaAritmetica, c->at(2), c->at(3), elapsedTime);
            else
            {
                if (c->at(3).compare("Exception"))
                    printTestResult(c->at(0), true, elapsedTime, resultFile, passed);
                else
                    printTestResult(c->at(0), false, elapsedTime, resultFile, failed);
                continue;
            }
            printTestResult(c->at(0), result, elapsedTime, resultFile, (result ? passed : failed));
        }
        catch (const string ex)
        {
            if (ex.compare("Exception") == 0)
                printTestResult(c->at(0), true, elapsedTime, resultFile, passed);
            else
                printTestResult(c->at(0), false, elapsedTime, resultFile, failed);
        }
    }
    printResume(passed, failed, cases->size(), resultFile);
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

void printTestResult(string id, bool result, double elapsedTime, ofstream &file, int &var)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    if (result)
        SetConsoleTextAttribute(color, 10); // Green
    else
        SetConsoleTextAttribute(color, 12); // Red
    
    string res = id + ": " + (result ? "Success. " : "Fail.    ");
    cout << res;
    file << res;
    SetConsoleTextAttribute(color, 7); // White
    cout << "Elapsed Time: " << fixed << elapsedTime << setprecision(5) << " milliseconds." << endl;
    file << "Elapsed Time: " << fixed << elapsedTime << setprecision(5) << " milliseconds." << endl;
    var++;
}

void printResume(int passed, int failed, int total, ofstream &file)
{
    HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(color, 7);
    cout << "\nTotal Test: " << total << ". " << "Passed: " << passed << ". " << "Failed: " << failed << "." << endl;
    file << "\nTotal Test: " << total << ". " << "Passed: " << passed << ". " << "Failed: " << failed << "." << endl;
}

template<class F>
bool callTest(F function, string params, string returned, double &elapsedTime)
{
    chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

    bool result = Tester::testEqual(function, cast(split(params, ' ')), cast(returned));
    Sleep(100);
    
    chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
    
    elapsedTime = chrono::duration<double,milli>(end - start).count() - 100;

    return result;
}