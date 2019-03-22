#include <regex>
#include "Tester.h"
#include "Medias.h"
#include "MethodsMedias.h"

double Tester::cast(std::string input)
{
    std::regex isString("[a-zA-Z]+");
    if (std::regex_match(input, isString) == true)
        throw input;

    return std::stod(input);
}

double* Tester::cast(std::vector<std::string>* input)
{
    int iLength = input->size();
    double* values = new double[iLength];

    try
    {
        for(int i = 0; i < iLength; i++)
            values[i] = Tester::cast(input->at(i));
    }
    catch (const std::string ex)
    {
        throw ex;
    }

    return values;
}

bool Tester::test(std::string method, std::vector<std::string>* input, std::string output)
{
    bool isInputArray = true;
    std::string exInput = "", exOutput = "";
    double* inputArray;
    double outputValue = 0.0;
    
    try
    {
        outputValue = Tester::cast(output);
    }
    catch(const std::string ex)
    {
        exOutput = ex;
    }
    
    try
    {
        inputArray = Tester::cast(input);
    }
    catch(const std::string ex)
    {
        isInputArray = true;
        exInput = ex;
    }
    

    try
    {
        if (method.compare(MethodsMedias::MEDIA_ARITMETICA) == 0)
        {
            if (isInputArray)
            {
                return Medias::mediaAritmetica(input->size(), inputArray) == outputValue;
            }
            else if (exInput.compare("NULL") == 0)
            {
                return Medias::mediaAritmetica(input->size(), NULL) == outputValue;
            }

            return false;
        }
        else if (method.compare(MethodsMedias::MEDIA_ARMONICA) == 0)
        {
            if (isInputArray)
            {
                return Medias::mediaArmonica(input->size(), inputArray) == outputValue;
            }
            else if (exInput.compare("NULL") == 0)
            {
                return Medias::mediaArmonica(input->size(), NULL) == outputValue;
            }

            return false;
        }
        else if (method.compare(MethodsMedias::MEDIA_GEOMETRICA) == 0)
        {
            Medias* medias = new Medias();

            if (isInputArray)
            {
                return medias->mediaGeometrica(input->size(), inputArray) == outputValue;
            }
            else if (exInput.compare("NULL") == 0)
            {
                return medias->mediaGeometrica(input->size(), NULL) == outputValue;
            }
            return false;
        }

        return false;
    }
    catch (const std::string ex)
    {
        if (exOutput.compare("Exception"))
            return true;
        return false;
    }
}