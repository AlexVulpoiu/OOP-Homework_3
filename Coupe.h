#include "Masina.h"

#ifndef TEMA3_COUPE_H
#define TEMA3_COUPE_H

class Coupe: public Masina
{
public:
    explicit Coupe(int a = 0, int gr = 0, int p = 0, const std::string& mrc = "", const std::string& mdl = "", const std::string& t = "");
    ~Coupe() override;
    Coupe(const Coupe& c);

    Coupe& operator =(const Coupe& c);

    friend std::istream& operator >>(std::istream& in, Coupe& c);

    friend void citire(std::istream& in, const int& n, Coupe *c);
    void afisare(std::ostream& out) const override;
};

#endif //TEMA3_COUPE_H
