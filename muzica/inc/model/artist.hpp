#ifndef ARTIST_HPP
#define ARTIST_HPP

#include <string>

// Artistul unei melodii.
// Nu are constructor fara parametri, deci un Artist trebuie
// creat mereu cu un nume si un gen.
class Artist
{
public:
    Artist(const std::string& nume, const std::string& gen);

    std::string getNume() const;
    std::string getGen() const;

private:
    std::string nume_;
    std::string gen_;
};

#endif
