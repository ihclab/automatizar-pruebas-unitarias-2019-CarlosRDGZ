#include <iostream>
#include <fstream>
#include <string>
#include "Medias.h"
using namespace std;

int main(int argc, char const *argv[])
{
    string line = "";
    ifstream* file = new ifstream("CasosPrueba.txt");

    if (file->is_open())
    {
        while(getline(*file, line))
        {
            cout << line << endl;
        }
    }

    file->close();

    return 0;
}
