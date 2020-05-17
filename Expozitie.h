#include <iostream>
#include <vector>
#include "Coupe.h"
#include "Hot_hatch.h"
#include "Cabrio.h"
#include "Supersport.h"
#include "Masina.h"

#ifndef TEMA3_EXPOZITIE_H
#define TEMA3_EXPOZITIE_H

template<class T> class Expozitie
{
private:
    int n;
    std::vector<std::pair<T, int>> masini;

public:
    explicit Expozitie(int nr = 0, std::vector<std::pair<T, int>> v = {})
    {
        n = nr;
        masini = v;
    };
    ~Expozitie() = default;
    Expozitie(const Expozitie<T>& e) = default;

    Expozitie& operator =(const Expozitie<T>& e) = default;

    friend std::ostream& operator <<(std::ostream& out, const Expozitie<T>& e)
    {
        int i;

        out << "Expozitie: " << e.n << '\n';
        for(i = 0; i < e.n; i++)
        {
            e.masini[i].first.afisare(out);
            out << e.masini[i].second << '\n';
        }
        out << "Final expozitie\n";

        return out;
    };

    void adauga_masina(T& masina, const int& p)
    {
        n++;
        masini.emplace_back(masina, p);
    };

    void vinde_masina(int& poz)
    {
        typename std::vector<std::pair<T, int>>::iterator it;
        int i;

        if(poz > masini.size())
        {
            std::cout << "nu avem " << poz << " masini expuse\n";
            return;
        }

        i = 1;
        for(it = masini.begin(); it != masini.end(); it++)
            if(i == poz)
            {
                it->second = (it->first).get_pret();
                break;
            }
            else
                i++;

        if(i != poz)
            std::cout << "masina ceruta nu este expusa\n";
    };

    int get_n()
    {
        return n;
    };
};

template<> class Expozitie<Supersport>
{
private:
    int nr_expuse, nr_vandute;
    std::vector<Supersport*> stoc, vandute;

public:
    explicit Expozitie<Supersport>(int nre = 0, int nrv = 0, std::vector<Supersport*> st = {}, std::vector<Supersport*> v = {})
    {
        nr_expuse = nre;
        nr_vandute = nrv;
        stoc = std::move(st);
        vandute = std::move(v);
    };
    ~Expozitie<Supersport>() = default;
    Expozitie<Supersport>(const Expozitie<Supersport>& e) = default;

    Expozitie<Supersport>& operator =(const Expozitie<Supersport>& e) = default;
    Expozitie<Supersport>& operator -=(Supersport* s)
    {
        std::vector<Supersport*>::iterator it;

        for(it = this->stoc.begin(); it != this->stoc.end(); it++)
            if(s == *it)
            {
                this->nr_expuse--;
                this->stoc.erase(it);
                this->nr_vandute++;
                this->vandute.push_back(s);
                break;
            }

        return *this;
    };

    friend std::ostream& operator <<(std::ostream& out, Expozitie<Supersport>& e)
    {
        int i;

        out << "Expozitie Supersport:\nNumar masini expuse: " << e.nr_expuse << '\n';
        for(i = 0; i < e.nr_expuse; i++)
        {
            e.stoc[i]->afisare(out);
            out << ' ';
        }
        out << "\nNumar masini vandute: " << e.nr_vandute << '\n';
        for(i = 0; i < e.nr_vandute; i++)
            e.vandute[i]->afisare(out);
        out << "\nFinal expozitie Supersport\n";

        return out;
    };

    void expune_masina(Supersport* s)
    {
        nr_expuse++;
        stoc.push_back(s);
    };

    int get_nr_expuse() const
    {
        return nr_expuse;
    }
};

#endif //TEMA3_EXPOZITIE_H
