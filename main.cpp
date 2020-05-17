#include <fstream>
#include <string>
#include "Masina.h"
#include "Coupe.h"
#include "Hot_hatch.h"
#include "Cabrio.h"
#include "Supersport.h"
#include "Expozitie.h"

int main()
{
    std::ifstream f("masini.in");
    std::ofstream g("masini.out");

    const int NMAX = 1005;
    int nr_masini_expuse, nr_masini_vandute, nr_ordine, i, nr_masini, nr_cabrio, nr_coupe, nr_hot_hatch, nr_supersport;
    std::string tip_masina;

    Cabrio cbr[NMAX];
    Coupe cp[NMAX];
    Hot_hatch hh[NMAX];
    Supersport ss[NMAX];
    Masina msn[NMAX];

    Expozitie<Masina> exp_msn;
    Expozitie<Cabrio> exp_cbr;
    Expozitie<Coupe> exp_cp;
    Expozitie<Hot_hatch> exp_hh;
    Expozitie<Supersport> exp_ss;


    nr_masini = nr_cabrio = nr_coupe = nr_hot_hatch = nr_supersport = 0;
    f >> nr_masini_expuse;  /// citesc mai multe masini si le adaug in expozitia corespunzatoare
    for(i = 0; i < nr_masini_expuse; i++)
    {
        f >> tip_masina;    /// citesc tipul masinii curente
        if(tip_masina == "cabrio")
        {
            f >> cbr[nr_cabrio];                 /// in functie de tip, citesc un obiect corespunzator
            cbr[nr_cabrio].set_tip(tip_masina); /// setez tipul obiectului citit
            exp_cbr.adauga_masina(cbr[nr_cabrio], -1);
            nr_cabrio++;
        }
        else
            if(tip_masina == "coupe")
            {
                f >> cp[nr_coupe];
                cp[nr_coupe].set_tip(tip_masina);
                exp_cp.adauga_masina(cp[nr_coupe], -1);
                nr_coupe++;
            }
            else
                if(tip_masina == "hot-hatch")
                {
                    f >> hh[nr_hot_hatch];
                    hh[nr_hot_hatch].set_tip(tip_masina);
                    exp_hh.adauga_masina(hh[nr_hot_hatch], -1);
                    nr_hot_hatch++;
                }
                else
                    if(tip_masina == "supersport")
                    {
                        f >> ss[nr_supersport];
                        ss[nr_supersport].set_tip(tip_masina);
                        exp_ss.expune_masina(&ss[nr_supersport]);
                        nr_supersport++;
                    }
                    else    /// pot avea masini care nu au unul dintre tipurile de mai sus si le tratez ca pe masini obisnuite
                    {
                        f >> msn[nr_masini];
                        msn[nr_masini].set_tip(tip_masina);
                        exp_msn.adauga_masina(msn[nr_masini], -1);
                        nr_masini++;
                    }
    }

    f >> nr_masini_vandute;
    for(i = 0; i < nr_masini_vandute; i++)
    {
        f >> tip_masina >> nr_ordine;   /// vreau sa vand masina de tipul citit, care a fost adaugata in expozitie pe pozitia nr_ordine
        if(tip_masina == "cabrio")      /// daca nu se poate, se afiseaza un mesaj corespunzator in consola
            exp_cbr.vinde_masina(nr_ordine);
        else
            if(tip_masina == "coupe")
                exp_cp.vinde_masina(nr_ordine);
            else
                if(tip_masina == "hot-hatch")
                    exp_hh.vinde_masina(nr_ordine);
                else
                    if(tip_masina == "supersport")
                    {
                        if(nr_ordine > nr_supersport)
                            std::cout << "nu sunt expuse destule masini supersport\n";
                        exp_ss -= (&ss[nr_ordine - 1]);
                    }
                    else
                        exp_msn.vinde_masina(nr_ordine);
    }

    g << exp_cbr << '\n' << exp_cp << '\n' << exp_hh << '\n' << exp_msn << '\n' << exp_ss << '\n';

    f.close();
    g.close();

    return 0;
}
