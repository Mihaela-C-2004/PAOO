#include <util/registru.hpp>
#include <iostream>

Registru::Registru()
    : numarCarti_(0)
{
    std::cout << "  [Registru] Constructor: registrul a fost creat la prima folosire" << std::endl;
}

void Registru::inregistreaza()
{
    numarCarti_++;
}

int Registru::getNumarCarti() const
{
    return numarCarti_;
}

// Item 4: obiectul static local este creat la PRIMUL apel al functiei.
// Asa e garantat ca exista inainte sa fie folosit, indiferent din ce
// fisier .cpp si in ce ordine sunt create obiectele globale.
Registru& registru()
{
    static Registru r;
    return r;
}
