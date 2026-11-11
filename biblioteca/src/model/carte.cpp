#include <model/carte.hpp>
#include <util/registru.hpp>
#include <cstring>
#include <iostream>

// Item 4: TOTI membrii primesc o valoare in lista de initializare,
// inclusiv int-ul, care altfel ar avea o valoare intamplatoare.
Carte::Carte()
    : titlu_(new char[std::strlen("Fara titlu") + 1]),
      pagini_(0)
{
    std::strcpy(titlu_, "Fara titlu");
    registru().inregistreaza();
    std::cout << "  [Carte] Constructor implicit: \"" << titlu_ << "\"" << std::endl;
}

Carte::Carte(const char* titlu, int pagini)
    : titlu_(new char[std::strlen(titlu) + 1]),
      pagini_(pagini)
{
    std::strcpy(titlu_, titlu);
    registru().inregistreaza();
    std::cout << "  [Carte] Constructor: \"" << titlu_ << "\"" << std::endl;
}

Carte::Carte(const Carte& other)
    : titlu_(new char[std::strlen(other.titlu_) + 1]),
      pagini_(other.pagini_)
{
    std::strcpy(titlu_, other.titlu_);
    registru().inregistreaza();
    std::cout << "  [Carte] Copy constructor: \"" << titlu_ << "\"" << std::endl;
}

Carte& Carte::operator=(const Carte& other)
{
    std::cout << "  [Carte] operator=: \"" << titlu_ << "\" <- \"" << other.titlu_ << "\""
              << std::endl;

    // Item 11: verificam auto-atribuirea (c = c)
    if (this == &other) {
        std::cout << "  [Carte] operator=: auto-atribuire, nu fac nimic" << std::endl;
        return *this;
    }

    // Item 11: copiem INTAI, stergem DUPA.
    // Daca new ar esua, obiectul ramane neschimbat.
    char* copie = new char[std::strlen(other.titlu_) + 1];
    std::strcpy(copie, other.titlu_);
    delete[] titlu_;
    titlu_ = copie;
    pagini_ = other.pagini_;

    // Item 10: returnam o referinta la obiectul curent
    return *this;
}

Carte::~Carte()
{
    std::cout << "  [Carte] Destructor: sterg \"" << titlu_ << "\"" << std::endl;
    delete[] titlu_;
}

const char* Carte::getTitlu() const
{
    return titlu_;
}

int Carte::getPagini() const
{
    return pagini_;
}

void Carte::afiseaza() const
{
    std::cout << titlu_ << " (" << pagini_ << " pagini)";
}
