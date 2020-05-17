#include "Masina.h"
#include <iostream>

Masina::Masina(int a, int gr, int p, std::string mrc, std::string mdl, std::string t)
{
    an_fabricatie = a;
    greutate = gr;
    pret = p;
    marca = std::move(mrc);
    model = std::move(mdl);
    tip = std::move(t);
}

Masina::~Masina() = default;

Masina::Masina(const Masina& m) = default;

Masina& Masina::operator =(const Masina& m) = default;

std::istream& operator >>(std::istream& in, Masina& m)
{
    in >> m.an_fabricatie >> m.greutate >> m.pret;
    in >> m.marca >> m.model;

    return in;
}

void citire(std::istream& in, const int& n, Masina *m)
{
    int i;

    for(i = 0; i < n; i++)
        in >> m[i];
}

void Masina::afisare(std::ostream& out) const
{
    out << an_fabricatie << ' ' << greutate << ' ' << pret << '\n';
    out << marca << ' ' << model << ' ' << clasa << ' ' << tip << '\n';
}

std::string Masina::get_clasa()
{
    return clasa;
}

void Masina::set_tip(std::string t)
{
    tip = std::move(t);
}

int Masina::get_pret() const
{
    return pret;
}

std::string Masina::clasa = "sport";
