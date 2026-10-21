#include <model/artist.hpp>
#include <iostream>

// Lista de initializare + valori initiale daca datele lipsesc
Artist::Artist(const std::string& nume, const std::string& gen)
    : nume_(nume.empty() ? "Necunoscut" : nume),
      gen_(gen.empty() ? "Nespecificat" : gen)
{
    std::cout << "  [Artist] Constructor: " << nume_ << " (" << gen_ << ")" << std::endl;
}

std::string Artist::getNume() const
{
    return nume_;
}

std::string Artist::getGen() const
{
    return gen_;
}
