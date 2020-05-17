#include "Supersport.h"
#include <iostream>

Supersport::Supersport(int a, int gr, int p, const std::string& mrc, const std::string& mdl, const std::string& t, int vmax, float acc):
        Masina(a, gr, p, mrc, mdl, t), viteza_maxima{vmax}, acceleratie{acc} {}

Supersport::~Supersport() = default;

Supersport::Supersport(const Supersport &s) = default;

Supersport& Supersport::operator =(const Supersport &s) = default;

std::istream& operator >>(std::istream& in, Supersport& s)
{
    in >> (Masina&)s;
    in >> s.viteza_maxima >> s.acceleratie;

    return in;
}

void citire(std::istream& in, const int& n, Supersport *s)
{
    int i;

    for(i = 0; i < n; i++)
        in >> s[i];
}

void Supersport::afisare(std::ostream &out) const
{
    out << an_fabricatie << ' ' << greutate << ' ' << pret << '\n';
    out << marca << ' ' << model << ' ' << clasa << ' ' << tip << '\n';
    out << viteza_maxima << ' ' << acceleratie << '\n';
}
