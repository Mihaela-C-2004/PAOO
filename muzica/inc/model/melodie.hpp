#ifndef MELODIE_HPP
#define MELODIE_HPP

#include <model/artist.hpp>

// O melodie. Titlul este alocat pe heap (char*).
class Melodie
{
public:
    Melodie(const char* titlu, const Artist& artist, int durata);
    Melodie(const Melodie& other);   // copy constructor
    ~Melodie();                      // destructor

    const char* getTitlu() const;
    int getDurata() const;
    void afiseaza() const;

private:
    char*     titlu_;   // pe heap
    Artist    artist_;  // nu are constructor fara parametri
    const int durata_;  // const, in secunde
};

#endif
