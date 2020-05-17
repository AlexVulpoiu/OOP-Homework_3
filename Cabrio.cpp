#include "Cabrio.h"
#include <iostream>

Cabrio::Cabrio(int a, int gr, int p, const std::string& mrc, const std::string& mdl, const std::string& t, std::string plf):
    Masina(a, gr, p, mrc, mdl, t), plafon{std::move(plf)} {}

Cabrio::~Cabrio() = default;

Cabrio::Cabrio(const Cabrio &c) = default;

Cabrio& Cabrio::operator =(const Cabrio &c) = default;

std::istream& operator >>(std::istream& in, Cabrio& c)
{
    in >> (Masina&)c;
    try
    {
        in >> c.plafon;
        throw c.plafon;
    }
    catch(std::string& x)
    {
        if(x != "textil" && x != "metalic")
        {
            std::cout << "tipul plafonului este incorect\nIntroduceti de la tastatura textil sau metalic\n";
            std::cin >> c.plafon;   /// daca numele plafonului este introdus gresit, greseala poate fi reparata de la tastatura
        }

        return in;
    }
}

void citire(std::istream& in, const int& n, Cabrio *c)
{
    int i;

    for(i = 0; i < n; i++)
        in >> c[i];
}

void Cabrio::afisare(std::ostream &out) const
{
    out << an_fabricatie << ' ' << greutate << ' ' << pret << '\n';
    out << marca << ' ' << model << ' ' << clasa << ' ' << tip << '\n';
    out << plafon << '\n';
}
