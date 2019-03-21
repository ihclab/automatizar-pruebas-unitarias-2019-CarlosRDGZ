#include <cstdarg>
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
double Medias::mediaGeometrica(int length, ...)
{
    va_list values;
    va_start(values, length);

    double x = 1;
    for(int i = 0; i < length; i++) { x *= va_arg(values, double); }
    va_end(values);
    
    return raizEnesima(x, length);
}

// public
double Medias::mediaArmonica(int length, ...)
{
    va_list values;
    va_start(values, length);

    double x = 0;
    for(int i = 0; i < length; i++) { x += (1.0 / va_arg(values, double)); }
    va_end(values);
    
    return length / x;
}

// public
// Calcula y regresa la media artimética
double Medias::mediaAritmetica(int length, ...)
{
    va_list values;
    va_start(values, length);

    double x = 0;
    for(int i = 0; i < length; i++) { x += va_arg(values, double); }
    va_end(values);
    
    return x / length;
}