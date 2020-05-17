#include <string>

#ifndef TEMA3_MASINA_H
#define TEMA3_MASINA_H

class Masina
{
protected:
    int an_fabricatie{}, greutate{}, pret{};
    std::string marca, model, tip;
    static std::string clasa;

public:
    explicit Masina(int a = 0, int gr = 0, int p = 0, std::string mrc = "", std::string mdl = "", std::string t = "");
    virtual ~Masina();
    Masina(const Masina& m);

    Masina& operator =(const Masina& m);

    friend std::istream& operator >>(std::istream& in, Masina& m);

    friend void citire(std::istream& in, const int& n, Masina *m);
    virtual void afisare(std::ostream& out) const;

    static std::string get_clasa();
    void set_tip(std::string t);
    int get_pret() const;
};

#endif //TEMA3_MASINA_H
