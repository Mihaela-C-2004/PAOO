#include <model/carte_digitala.hpp>
#include <iostream>

CarteDigitala::CarteDigitala(const char* titlu, int pagini, const std::string& format)
    : Carte(titlu, pagini),
      format_(format)
{
    std::cout << "  [CarteDigitala] Constructor: format " << format_ << std::endl;
}

// Item 12: copiem si partea de BAZA, apeland copy constructor-ul din Carte
CarteDigitala::CarteDigitala(const CarteDigitala& other)
    : Carte(other),
      format_(other.format_)
{
    std::cout << "  [CarteDigitala] Copy constructor: format " << format_ << std::endl;
}

// Item 12: apelam si operator= din clasa de baza
CarteDigitala& CarteDigitala::operator=(const CarteDigitala& other)
{
    std::cout << "  [CarteDigitala] operator=" << std::endl;
    if (this == &other) {          // Item 11
        return *this;
    }
    Carte::operator=(other);       // copiaza titlul si paginile
    format_ = other.format_;       // copiaza partea proprie
    return *this;                  // Item 10
}

CarteDigitala::~CarteDigitala()
{
    std::cout << "  [CarteDigitala] Destructor: format " << format_ << std::endl;
}

void CarteDigitala::afiseaza() const
{
    Carte::afiseaza();
    std::cout << " - format " << format_;
}
