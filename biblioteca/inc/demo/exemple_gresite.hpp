#ifndef EXEMPLE_GRESITE_HPP
#define EXEMPLE_GRESITE_HPP

#include <model/carte.hpp>
#include <string>

// Clase scrise GRESIT intentionat, ca sa se vada problemele
// descrise in Item 4, Item 10, Item 11 si Item 12.

// Item 4: constructorul uita sa initializeze un membru de tip int
class CarteNeinitializata
{
public:
    CarteNeinitializata(int pagini);

    int getNumarImprumuturi() const;

private:
    int numarImprumuturi_;   // NU este initializat
    int pagini_;
};

// Item 10 + Item 11: operator= returneaza void si nu verifica auto-atribuirea
class CarteAtribuireGresita
{
public:
    CarteAtribuireGresita(const char* titlu);
    CarteAtribuireGresita(const CarteAtribuireGresita& other);
    ~CarteAtribuireGresita();

    void operator=(const CarteAtribuireGresita& other);   // returneaza void

    const char* getTitlu() const;

private:
    char* titlu_;
};

// Item 12: nu copiaza partea de baza (Carte)
class CarteDigitalaGresita : public Carte
{
public:
    CarteDigitalaGresita(const char* titlu, int pagini, const std::string& format);
    CarteDigitalaGresita(const CarteDigitalaGresita& other);
    CarteDigitalaGresita& operator=(const CarteDigitalaGresita& other);

    void afiseaza() const;

private:
    std::string format_;
};

#endif
