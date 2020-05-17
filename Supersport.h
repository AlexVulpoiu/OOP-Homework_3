#include "Masina.h"

#ifndef TEMA3_SUPERSPORT_H
#define TEMA3_SUPERSPORT_H

class Supersport: public Masina
{
private:
    int viteza_maxima{};
    float acceleratie{};

public:
    explicit Supersport(int a = 0, int gr = 0, int p = 0, const std::string& mrc = "", const std::string& mdl = "", const std::string& t = "", int vmax = 0, float acc = 0.0);
    ~Supersport() override;
    Supersport(const Supersport& s);

    Supersport& operator =(const Supersport& s);

    friend std::istream& operator >>(std::istream& in, Supersport& s);

    friend void citire(std::istream& in, const int& n, Supersport *s);
    void afisare(std::ostream& out) const override;
};

#endif //TEMA3_SUPERSPORT_H
