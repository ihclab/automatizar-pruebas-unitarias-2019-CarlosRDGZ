#ifndef MEDIAS_H
#define MEDIAS_H

class Medias
{
private:
    static double raizEnesima(double x, int n);
public:
    double mediaGeometrica(int length, ...);
    static double mediaArmonica(int length, ...);
    static double mediaAritmetica(int length, ...);
};

#endif