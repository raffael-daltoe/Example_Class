#include <iostream>
#include <sstream>
using namespace std;
class NumeroComplexo
{
private:
    double real;
    double imag;

public:
    NumeroComplexo(double r = 0.0, double i = 0.0);
    void define(double r, double i);
    double parteReal();
    double parteImaginaria();
    string toString();
    NumeroComplexo operator+(NumeroComplexo &nc)
    {
        return NumeroComplexo(real + nc.parteReal(), imag + nc.parteImaginaria());
    }
    bool operator==(NumeroComplexo &nc)
    {
        return nc.parteReal() == nc.parteImaginaria();
    }
    bool operator!=(NumeroComplexo &nc)
    {
        return nc.parteReal() != nc.parteImaginaria();
    }
};
NumeroComplexo::NumeroComplexo(double r, double i)
{
    define(r, i);
}
void NumeroComplexo::define(double r, double i)
{
    real = r;
    imag = i;
}
double NumeroComplexo::parteReal()
{
    return real;
}
double NumeroComplexo::parteImaginaria()
{
    return imag;
}
string NumeroComplexo::toString()
{
    stringstream ss;
    if (imag != 0.0)
        ss << real << "+" << imag << ".i";
    else
        ss << real;
    return ss.str();
}
int main()
{
    NumeroComplexo um(1, 0), i(0, 1), nc1(1, 1), nc2(1, 2), nc3(2, 1), nc4;
    cout << "1: " << um.toString() << endl;
    cout << "i: " << i.toString() << endl;
    nc4 = i + um;
    cout << "1+i: " << nc4.toString() << endl;
    if (nc4 == nc1)
        cout << "IGUAL" << endl;
    if (nc4 != nc2)
        cout << "DIFERENTE" << endl;
    if (nc4 != nc3)
        cout << "DIFERENTE" << endl;
    return 0;
}