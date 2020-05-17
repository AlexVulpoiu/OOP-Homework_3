#include "Hot_hatch.h"
#include <iostream>

Hot_hatch::Hot_hatch(int a, int gr, int p, const std::string& mrc, const std::string& mdl, const std::string& t, int cp, std::string tr):
        Masina(a, gr, p, mrc, mdl, t), cai_putere{cp}, tractiune{std::move(tr)} {}

Hot_hatch::~Hot_hatch() = default;

Hot_hatch::Hot_hatch(const Hot_hatch& h) = default;

Hot_hatch& Hot_hatch::operator =(const Hot_hatch &h) = default;

std::istream& operator >>(std::istream& in, Hot_hatch& h)
{
    in >> (Masina&)h;
    in >> h.cai_putere;
    try
    {
        in >> h.tractiune;
        throw h.tractiune;
    }
    catch(std::string& x)
    {
        if(h.tractiune != "FWD" && h.tractiune != "AWD" && h.tractiune != "RWD")
        {
            std::cout << "tipul tractiunii este incorect\nIntroduceti de la tastatura AWD, FWD sau RWD\n";
            std::cin >> h.tractiune;    /// daca tipul tractiunii este introdus gresit, il putem reintroduce de la tastatura
        }

        return in;
    }
}

void citire(std::istream& in, const int& n, Hot_hatch *h)
{
    int i;

    for(i = 0; i < n; i++)
        in >> h[i];
}

void Hot_hatch::afisare(std::ostream &out) const
{
    out << an_fabricatie << ' ' << greutate << ' ' << pret << '\n';
    out << marca << ' ' << model << ' ' << clasa << ' ' << tip << '\n';
    out << cai_putere << ' ' << tractiune << '\n';
}
