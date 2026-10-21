#ifndef EXEMPLE_GRESITE_HPP
#define EXEMPLE_GRESITE_HPP

// Clase scrise GRESIT intentionat, ca sa se vada ce se intampla
// cand lipseste destructorul sau copy constructor-ul.

// Aloca memorie pe heap, dar NU are destructor => memory leak
class MelodieFaraDestructor
{
public:
    MelodieFaraDestructor(const char* titlu);

private:
    char* titlu_;
};

// Are destructor, dar NU are copy constructor.
// Compilatorul face unul care copiaza doar pointerul.
class MelodieFaraCopyConstructor
{
public:
    MelodieFaraCopyConstructor(const char* titlu);
    ~MelodieFaraCopyConstructor();

    void schimbaPrimaLitera(char litera);
    const char* getTitlu() const;
    void* getAdresa() const;

private:
    char* titlu_;
};

#endif
