#ifndef MEDIAS_H
#define MEDIAS_H

class Medias
{
private:
    static double raizEnesima(double x, int n);
public:
    double mediaGeometrica(int length, double* vals);
    static double mediaArmonica(int length, double* vals);
    static double mediaAritmetica(int length, double* vals);
};

#endif