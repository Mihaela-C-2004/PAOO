#include <demo/exemple_gresite.hpp>
#include <cstring>
#include <iostream>

MelodieFaraDestructor::MelodieFaraDestructor(const char* titlu)
    : titlu_(new char[std::strlen(titlu) + 1])
{
    std::strcpy(titlu_, titlu);
    std::cout << "  [FaraDestructor] Constructor: am alocat \"" << titlu_ << "\"" << std::endl;
}

MelodieFaraCopyConstructor::MelodieFaraCopyConstructor(const char* titlu)
    : titlu_(new char[std::strlen(titlu) + 1])
{
    std::strcpy(titlu_, titlu);
    std::cout << "  [FaraCopyConstructor] Constructor: \"" << titlu_ << "\"" << std::endl;
}

MelodieFaraCopyConstructor::~MelodieFaraCopyConstructor()
{
    std::cout << "  [FaraCopyConstructor] Destructor: sterg memoria de la adresa "
              << static_cast<void*>(titlu_) << std::endl;
    delete[] titlu_;
}

void MelodieFaraCopyConstructor::schimbaPrimaLitera(char litera)
{
    titlu_[0] = litera;
}

const char* MelodieFaraCopyConstructor::getTitlu() const
{
    return titlu_;
}

void* MelodieFaraCopyConstructor::getAdresa() const
{
    return titlu_;
}
