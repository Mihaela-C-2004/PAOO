#ifndef CARTE_DIGITALA_HPP
#define CARTE_DIGITALA_HPP

#include <model/carte.hpp>
#include <string>

// O carte in format electronic.
// Mosteneste Carte si adauga formatul fisierului (PDF, EPUB...).
class CarteDigitala : public Carte
{
public:
    CarteDigitala(const char* titlu, int pagini, const std::string& format);
    CarteDigitala(const CarteDigitala& other);
    CarteDigitala& operator=(const CarteDigitala& other);
    ~CarteDigitala();

    void afiseaza() const;

private:
    std::string format_;
};

#endif
