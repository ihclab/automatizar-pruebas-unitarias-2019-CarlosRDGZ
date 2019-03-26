#ifndef MEDIAS_H
#define MEDIAS_H

class Medias
{
private:
    static double raizEnesima(double x, int n);
public:
    double mediaGeometrica(std::vector<double>* vals);
    static double mediaArmonica(std::vector<double>* vals);
    static double mediaAritmetica(std::vector<double>* vals);
};

#endif