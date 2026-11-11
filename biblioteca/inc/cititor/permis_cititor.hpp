#ifndef PERMIS_CITITOR_HPP
#define PERMIS_CITITOR_HPP

#include <imprumut/imprumut.hpp>
#include <string>

// Permisul de biblioteca al unui cititor. Fiecare permis este UNIC,
// deci nu are sens sa poata fi copiat.
//
// Item 6: interzicem copierea cu "= delete".
class PermisCititor
{
public:
    PermisCititor(int numar, const std::string& nume, const Imprumut& imprumut);

    PermisCititor(const PermisCititor&) = delete;              // fara copiere
    PermisCititor& operator=(const PermisCititor&) = delete;   // fara atribuire

    void afiseaza() const;

private:
    const int   numar_;
    std::string nume_;
    Imprumut    imprumutCurent_;
};

#endif
