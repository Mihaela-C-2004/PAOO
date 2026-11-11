#include <imprumut/imprumut.hpp>
#include <iostream>

Imprumut::Imprumut(const std::string& cititor, int zile, const Carte& carte)
    : cititor_(cititor),
      zile_(zile),
      carte_(carte)
{
    std::cout << "  [Imprumut] Constructor: " << cititor_ << std::endl;
}

void Imprumut::afiseaza() const
{
    std::cout << "    Imprumut: " << cititor_ << ", " << zile_ << " zile, cartea ";
    carte_.afiseaza();
    std::cout << std::endl;
}
