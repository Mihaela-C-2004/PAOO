#include <model/melodie.hpp>
#include <cstring>
#include <iostream>

// Constructor cu lista de initializare.
// artist_ si durata_ POT fi initializati DOAR aici:
//  - Artist nu are constructor fara parametri
//  - durata_ este const
Melodie::Melodie(const char* titlu, const Artist& artist, int durata)
    : titlu_(nullptr),
      artist_(artist),
      durata_(durata > 0 ? durata : 0)     // validare: fara durate negative
{
    if (titlu == nullptr || std::strlen(titlu) == 0) {
        titlu = "Fara titlu";
    }
    titlu_ = new char[std::strlen(titlu) + 1];
    std::strcpy(titlu_, titlu);
    std::cout << "  [Melodie] Constructor: \"" << titlu_ << "\"" << std::endl;
}

// Copy constructor: aloca memorie NOUA pentru titlu (deep copy)
Melodie::Melodie(const Melodie& other)
    : titlu_(new char[std::strlen(other.titlu_) + 1]),
      artist_(other.artist_),
      durata_(other.durata_)
{
    std::strcpy(titlu_, other.titlu_);
    std::cout << "  [Melodie] Copy constructor: \"" << titlu_ << "\"" << std::endl;
}

// Destructor: elibereaza titlul de pe heap
Melodie::~Melodie()
{
    std::cout << "  [Melodie] Destructor: sterg \"" << titlu_ << "\"" << std::endl;
    delete[] titlu_;
}

const char* Melodie::getTitlu() const
{
    return titlu_;
}

int Melodie::getDurata() const
{
    return durata_;
}

void Melodie::afiseaza() const
{
    std::cout << titlu_ << " - " << artist_.getNume() << " (" << durata_ << " sec)"
              << "  [titlu la adresa " << static_cast<void*>(titlu_) << "]";
}
