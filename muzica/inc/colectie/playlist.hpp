#ifndef PLAYLIST_HPP
#define PLAYLIST_HPP

#include <model/melodie.hpp>

// Un playlist: numele si melodiile sunt alocate pe heap.
class Playlist
{
public:
    Playlist(const char* nume, int capacitate);
    Playlist(const Playlist& other);       // copy constructor
    Playlist(Playlist&& other) noexcept;   // move constructor
    ~Playlist();                           // destructor

    void adauga(const Melodie& melodie);
    const char* getNume() const;
    int getNumarMelodii() const;
    void afiseaza() const;

private:
    char*     nume_;        // pe heap
    Melodie** melodii_;     // vector pe heap cu pointeri spre melodii
    int       numar_;
    int       capacitate_;
};

#endif
