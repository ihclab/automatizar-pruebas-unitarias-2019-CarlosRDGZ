#include <cmath>
#include "Medias.h"

// private
// Calcula y regresa la raíz enésima = x^(1/n)
double Medias::raizEnesima(double x, int n)
{
    return pow(x, (1.0 / n));
}

// public
// Usa raizEnesima para calcular y regresar la media geométrica
double Medias::mediaGeometrica(int length, double* vals)
{
    for(int i = 1; i < length; i++) { vals[0] *= vals[i]; }   
    return raizEnesima(vals[0], length);
}

// public
double Medias::mediaArmonica(int length, double* vals)
{
    double x = 0;
    for(int i = 0; i < length; i++) { x += (1.0 / vals[i]); }
    
    return length / x;
}

// public
// Calcula y regresa la media artimética
double Medias::mediaAritmetica(int length, double* vals)
{
    for(int i = 1; i < length; i++) { vals[0] += vals[i]; }   
    return vals[0] / length;
}