#include "Coupe.h"
#include <iostream>

Coupe::Coupe(int a, int gr, int p, const std::string& mrc, const std::string& mdl, const std::string& t): Masina(a, gr, p, mrc, mdl, t) {}

Coupe::~Coupe() = default;

Coupe::Coupe(const Coupe& c) = default;

Coupe& Coupe::operator =(const Coupe &c) = default;

std::istream& operator >>(std::istream& in, Coupe& c)
{
    in >> (Masina&)c;

    return in;
}

void citire(std::istream& in, const int& n, Coupe *c)
{
    int i;

    for(i = 0; i < n; i++)
        in >> c[i];
}

void Coupe::afisare(std::ostream& out) const
{
    out << an_fabricatie << ' ' << greutate << ' ' << pret << '\n';
    out << marca << ' ' << model << ' ' << clasa << ' ' << tip << '\n';
}
