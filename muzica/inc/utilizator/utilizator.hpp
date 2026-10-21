#ifndef UTILIZATOR_HPP
#define UTILIZATOR_HPP

#include <colectie/playlist.hpp>
#include <string>

// Un utilizator care detine un playlist.
class Utilizator
{
public:
    Utilizator(const std::string& nume, Playlist&& playlist);

    void afiseaza() const;

private:
    std::string nume_;
    Playlist    playlist_;   // nu are constructor fara parametri
};

#endif
