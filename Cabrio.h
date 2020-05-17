#include "Masina.h"
#include <string>

#ifndef TEMA3_CABRIO_H
#define TEMA3_CABRIO_H

class Cabrio: public Masina
{
private:
    std::string plafon;

public:
    explicit Cabrio(int a = 0, int gr = 0, int p = 0, const std::string& mrc = "", const std::string& mdl = "", const std::string& t = "", std::string plf = "");
    ~Cabrio() override;
    Cabrio(const Cabrio& c);

    Cabrio& operator =(const Cabrio& c);

    friend std::istream& operator >>(std::istream& in, Cabrio& c);

    friend void citire(std::istream& in, const int& n, Cabrio *c);
    void afisare(std::ostream& out) const override;
};

#endif //TEMA3_CABRIO_H
