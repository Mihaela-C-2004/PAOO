#include <colectie/playlist.hpp>
#include <cstring>
#include <iostream>

// Constructor cu lista de initializare
Playlist::Playlist(const char* nume, int capacitate)
    : nume_(new char[std::strlen(nume) + 1]),
      melodii_(new Melodie*[capacitate]),
      numar_(0),                  // valoare initiala: playlist gol
      capacitate_(capacitate)
{
    std::strcpy(nume_, nume);
    std::cout << "  [Playlist] Constructor: \"" << nume_ << "\"" << std::endl;
}

// Copy constructor: aloca memorie NOUA si copiaza fiecare melodie
Playlist::Playlist(const Playlist& other)
    : nume_(new char[std::strlen(other.nume_) + 1]),
      melodii_(new Melodie*[other.capacitate_]),
      numar_(other.numar_),
      capacitate_(other.capacitate_)
{
    std::strcpy(nume_, other.nume_);
    std::cout << "  [Playlist] Copy constructor: copiez \"" << nume_ << "\"" << std::endl;
    for (int i = 0; i < numar_; i++) {
        melodii_[i] = new Melodie(*other.melodii_[i]);   // copy constructor Melodie
    }
}

// Move constructor: preia pointerii, NU copiaza nimic.
// Sursa ramane goala, ca destructorul ei sa nu stearga memoria.
Playlist::Playlist(Playlist&& other) noexcept
    : nume_(other.nume_),
      melodii_(other.melodii_),
      numar_(other.numar_),
      capacitate_(other.capacitate_)
{
    other.nume_ = nullptr;
    other.melodii_ = nullptr;
    other.numar_ = 0;
    other.capacitate_ = 0;
    std::cout << "  [Playlist] Move constructor: am preluat \"" << nume_ << "\"" << std::endl;
}

// Destructor: sterge fiecare melodie, apoi vectorul si numele
Playlist::~Playlist()
{
    if (nume_ == nullptr) {
        std::cout << "  [Playlist] Destructor: playlist mutat, nu am nimic de sters"
                  << std::endl;
        return;
    }
    std::cout << "  [Playlist] Destructor: sterg \"" << nume_ << "\"" << std::endl;
    for (int i = 0; i < numar_; i++) {
        delete melodii_[i];
    }
    delete[] melodii_;
    delete[] nume_;
}

// Incapsulare: melodiile se adauga doar prin aceasta metoda, cu verificare
void Playlist::adauga(const Melodie& melodie)
{
    if (numar_ >= capacitate_) {
        std::cout << "  [Playlist] Nu mai este loc in \"" << nume_ << "\"" << std::endl;
        return;
    }
    melodii_[numar_] = new Melodie(melodie);
    numar_++;
}

const char* Playlist::getNume() const
{
    return nume_;
}

int Playlist::getNumarMelodii() const
{
    return numar_;
}

void Playlist::afiseaza() const
{
    if (nume_ == nullptr) {
        std::cout << "    Playlist gol (a fost mutat)" << std::endl;
        return;
    }
    std::cout << "    Playlist \"" << nume_ << "\" (" << numar_ << " melodii)"
              << "  [melodii la adresa " << static_cast<void*>(melodii_) << "]" << std::endl;
    for (int i = 0; i < numar_; i++) {
        std::cout << "      " << i + 1 << ". ";
        melodii_[i]->afiseaza();
        std::cout << std::endl;
    }
}
