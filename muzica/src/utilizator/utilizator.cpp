#include <utilizator/utilizator.hpp>
#include <iostream>
#include <utility>

// playlist_ este initializat in lista, prin MUTARE (move constructor)
Utilizator::Utilizator(const std::string& nume, Playlist&& playlist)
    : nume_(nume),
      playlist_(std::move(playlist))
{
    std::cout << "  [Utilizator] Constructor: " << nume_ << std::endl;
}

void Utilizator::afiseaza() const
{
    std::cout << "    Utilizator " << nume_ << ":" << std::endl;
    playlist_.afiseaza();
}
