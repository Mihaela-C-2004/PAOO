#ifndef CARTE_HPP
#define CARTE_HPP

// O carte. Titlul este alocat pe heap (char*).
class Carte
{
public:
    Carte();                                   // valori initiale
    Carte(const char* titlu, int pagini);
    Carte(const Carte& other);                 // copy constructor
    Carte& operator=(const Carte& other);      // operator de atribuire
    virtual ~Carte();                          // virtual: Carte este clasa de baza

    const char* getTitlu() const;
    int getPagini() const;
    void afiseaza() const;

private:
    char* titlu_;   // pe heap
    int   pagini_;  // tip de baza: trebuie initializat explicit (Item 4)
};

#endif
