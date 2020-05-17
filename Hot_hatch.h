#include "Masina.h"
#include <string>

#ifndef TEMA3_HOT_HATCH_H
#define TEMA3_HOT_HATCH_H

class Hot_hatch: public Masina
{
private:
    int cai_putere{};
    std::string tractiune;

public:
    explicit Hot_hatch(int a = 0, int gr = 0, int p = 0, const std::string& mrc = "", const std::string& mdl = "", const std::string& t = "", int cp = 0, std::string tr = "");
    ~Hot_hatch() override;
    Hot_hatch(const Hot_hatch& h);

    Hot_hatch& operator =(const Hot_hatch& h);

    friend std::istream& operator >>(std::istream& in, Hot_hatch& h);

    friend void citire(std::istream& in, const int& n, Hot_hatch *h);
    void afisare(std::ostream& out) const override;
};

#endif //TEMA3_HOT_HATCH_H
