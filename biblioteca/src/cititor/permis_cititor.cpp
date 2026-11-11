#include <cititor/permis_cititor.hpp>
#include <iostream>

PermisCititor::PermisCititor(int numar, const std::string& nume, const Imprumut& imprumut)
    : numar_(numar),
      nume_(nume),
      imprumutCurent_(imprumut)
{
    std::cout << "  [PermisCititor] Constructor: #" << numar_ << " " << nume_ << std::endl;
}

void PermisCititor::afiseaza() const
{
    std::cout << "    Permis #" << numar_ << " (" << nume_ << ")" << std::endl;
    imprumutCurent_.afiseaza();
}
