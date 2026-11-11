#ifndef IMPRUMUT_HPP
#define IMPRUMUT_HPP

#include <model/carte.hpp>
#include <string>

// Un imprumut: ce carte a fost imprumutata, de cine si pe cate zile.
//
// Item 5: NU scriem copy constructor, operator= si destructor.
// Compilatorul le scrie singur si ele apeleaza automat
// functiile corespunzatoare pentru fiecare membru (inclusiv Carte).
class Imprumut
{
public:
    Imprumut(const std::string& cititor, int zile, const Carte& carte);

    void afiseaza() const;

private:
    std::string cititor_;
    int         zile_;
    Carte       carte_;
};

#endif
