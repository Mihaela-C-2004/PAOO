#include <demo/exemple_gresite.hpp>
#include <cstring>
#include <iostream>

// ---------- CarteNeinitializata ----------
CarteNeinitializata::CarteNeinitializata(int pagini)
    : pagini_(pagini)          // numarImprumuturi_ a fost uitat
{
    std::cout << "  [Neinitializata] Constructor: " << pagini_ << " pagini" << std::endl;
}

int CarteNeinitializata::getNumarImprumuturi() const
{
    return numarImprumuturi_;
}

// ---------- CarteAtribuireGresita ----------
CarteAtribuireGresita::CarteAtribuireGresita(const char* titlu)
    : titlu_(new char[std::strlen(titlu) + 1])
{
    std::strcpy(titlu_, titlu);
    std::cout << "  [AtribuireGresita] Constructor: \"" << titlu_ << "\"" << std::endl;
}

CarteAtribuireGresita::CarteAtribuireGresita(const CarteAtribuireGresita& other)
    : titlu_(new char[std::strlen(other.titlu_) + 1])
{
    std::strcpy(titlu_, other.titlu_);
}

CarteAtribuireGresita::~CarteAtribuireGresita()
{
    delete[] titlu_;
}

// GRESIT: sterge intai propriul titlu, apoi citeste din other.titlu_.
// Daca other este chiar obiectul curent, other.titlu_ tocmai a fost sters!
void CarteAtribuireGresita::operator=(const CarteAtribuireGresita& other)
{
    std::cout << "  [AtribuireGresita] operator=: sterg titlul meu, apoi copiez" << std::endl;
    delete[] titlu_;
    titlu_ = new char[std::strlen(other.titlu_) + 1];
    std::strcpy(titlu_, other.titlu_);
}

const char* CarteAtribuireGresita::getTitlu() const
{
    return titlu_;
}

// ---------- CarteDigitalaGresita ----------
CarteDigitalaGresita::CarteDigitalaGresita(const char* titlu, int pagini,
                                           const std::string& format)
    : Carte(titlu, pagini),
      format_(format)
{
}

// GRESIT: nu apeleaza Carte(other).
// Partea de baza este creata cu constructorul implicit => "Fara titlu".
CarteDigitalaGresita::CarteDigitalaGresita(const CarteDigitalaGresita& other)
    : format_(other.format_)
{
    std::cout << "  [DigitalaGresita] Copy constructor: am copiat doar formatul" << std::endl;
}

// GRESIT: nu apeleaza Carte::operator=(other).
// Titlul si numarul de pagini raman cele vechi.
CarteDigitalaGresita& CarteDigitalaGresita::operator=(const CarteDigitalaGresita& other)
{
    std::cout << "  [DigitalaGresita] operator=: am copiat doar formatul" << std::endl;
    format_ = other.format_;
    return *this;
}

void CarteDigitalaGresita::afiseaza() const
{
    Carte::afiseaza();
    std::cout << " - format " << format_;
}
