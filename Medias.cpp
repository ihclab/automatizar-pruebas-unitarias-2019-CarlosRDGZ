#include <cmath>
#include <vector>
#include "Medias.h"

// private
// Calcula y regresa la raíz enésima = x^(1/n)
double Medias::raizEnesima(double x, int n)
{
    return pow(x, (1.0 / n));
}

// public
// Usa raizEnesima para calcular y regresar la media geométrica
double Medias::mediaGeometrica(std::vector<double>* vals)
{
    for(int i = 1; i < vals->size(); i++) { vals->at(0) *= vals->at(i); }   
    return raizEnesima(vals->at(0), vals->size());
}

// public
double Medias::mediaArmonica(std::vector<double>* vals)
{
    double x = 0;
    for(int i = 0; i < vals->size(); i++) { x += (1.0 / vals->at(i)); }
    return vals->size() / x;
}

// public
// Calcula y regresa la media artimética
double Medias::mediaAritmetica(std::vector<double>* vals)
{
    for(int i = 1; i < vals->size(); i++) { vals->at(0) += vals->at(i); }   
    return vals->at(0) / vals->size();
}