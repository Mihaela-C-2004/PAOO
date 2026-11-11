#ifndef REGISTRU_HPP
#define REGISTRU_HPP

// Registrul bibliotecii numara toate cartile create in program.
// Este folosit din mai multe fisiere .cpp, deci NU il facem variabila globala.
// Il obtinem prin functia registru() (Item 4: obiect static local).
class Registru
{
public:
    Registru();

    void inregistreaza();
    int getNumarCarti() const;

private:
    int numarCarti_;
};

// Singura cale de a ajunge la registru
Registru& registru();

#endif
