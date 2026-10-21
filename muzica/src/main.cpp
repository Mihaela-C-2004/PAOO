#include <model/artist.hpp>
#include <model/melodie.hpp>
#include <colectie/playlist.hpp>
#include <utilizator/utilizator.hpp>
#include <demo/exemple_gresite.hpp>

#include <iostream>
#include <utility>

using namespace std;

void titlu(const char* text)
{
    cout << endl << "========== " << text << " ==========" << endl;
}

// ---------------------------------------------------------------
// 2. Incapsulare
// ---------------------------------------------------------------
void exempluIncapsulare()
{
    titlu("2. Incapsulare");

    Artist queen("Queen", "Rock");
    Melodie m1("Bohemian Rhapsody", queen, 354);
    Melodie m2("Melodie cu durata gresita", queen, -10);   // durata devine 0

    Playlist p("Rock", 2);
    p.adauga(m1);
    p.adauga(m2);
    p.adauga(m1);   // refuzat: playlist-ul e plin
    p.afiseaza();

    cout << "  Membrii sunt private, deci nu putem scrie p.numar_ = 100;" << endl;
    cout << "  Melodiile se pot adauga doar prin adauga(), care verifica locul." << endl;
}

// ---------------------------------------------------------------
// 3. Initializarea membrilor din constructor
// ---------------------------------------------------------------
void exempluInitializare()
{
    titlu("3. Initializarea membrilor din constructor");

    cout << "  Melodie are un Artist si o durata const." << endl;
    cout << "  Ele pot fi initializate DOAR in lista de initializare." << endl;
    cout << "  Daca am scrie in corpul constructorului  artist_ = artist;" << endl;
    cout << "  codul nu ar compila: Artist nu are constructor fara parametri." << endl;

    Artist anonim("", "");
    Melodie m("", anonim, 200);
    cout << "  Valori initiale pentru date lipsa: ";
    m.afiseaza();
    cout << endl;
}

// ---------------------------------------------------------------
// 4. Eliberarea heap-ului in destructor
// ---------------------------------------------------------------
void exempluDestructor()
{
    titlu("4. Eliberarea heap-ului in destructor");

    Artist abba("ABBA", "Pop");
    Melodie m("Dancing Queen", abba, 231);
    {
        Playlist temporar("Temporar", 2);
        temporar.adauga(m);
        cout << "  -- iesim din bloc, se apeleaza destructorul --" << endl;
    }
    cout << "  Destructorul a sters melodiile, vectorul si numele." << endl;

    cout << endl << "  Clasa FARA destructor:" << endl;
    {
        MelodieFaraDestructor fara("se pierde");
        cout << "  -- iesim din bloc --" << endl;
    }
    cout << "  Nu s-a afisat niciun destructor: memoria a ramas alocata (memory leak)."
         << endl;
}

// ---------------------------------------------------------------
// 5. Copy constructor
// ---------------------------------------------------------------
void exempluCopyConstructor()
{
    titlu("5. Copy constructor");

    Artist beatles("The Beatles", "Rock");
    Melodie m1("Yesterday", beatles, 125);
    Melodie m2("Hey Jude", beatles, 431);

    Playlist original("Beatles", 3);
    original.adauga(m1);

    cout << "  -- Playlist copie = original; --" << endl;
    Playlist copie = original;
    copie.adauga(m2);   // modificam doar copia

    original.afiseaza();
    copie.afiseaza();
    cout << "  Adresele sunt diferite, iar originalul nu s-a schimbat." << endl;
}

// ---------------------------------------------------------------
// 6. Move constructor
// ---------------------------------------------------------------
void exempluMoveConstructor()
{
    titlu("6. Move constructor");

    Artist coldplay("Coldplay", "Pop rock");
    Melodie m("Yellow", coldplay, 266);

    Playlist sursa("Seara", 2);
    sursa.adauga(m);
    sursa.afiseaza();

    cout << "  -- Playlist mutat = std::move(sursa); --" << endl;
    Playlist mutat = std::move(sursa);
    mutat.afiseaza();
    sursa.afiseaza();
    cout << "  Melodiile sunt la ACEEASI adresa: nu s-a copiat nimic," << endl;
    cout << "  doar s-a schimbat proprietarul." << endl;

    cout << endl << "  Playlist-ul este mutat in Utilizator:" << endl;
    Utilizator ana("Ana", std::move(mutat));
    ana.afiseaza();
}

// ---------------------------------------------------------------
// 5b. Ce se intampla FARA copy constructor (programul se opreste!)
// ---------------------------------------------------------------
void exempluFaraCopyConstructor()
{
    titlu("5b. Ce se intampla FARA copy constructor");

    MelodieFaraCopyConstructor original("imagine");
    {
        MelodieFaraCopyConstructor copie = original;
        cout << "  Adresa original: " << original.getAdresa() << endl;
        cout << "  Adresa copie:    " << copie.getAdresa() << "  <-- ACEEASI adresa!" << endl;

        copie.schimbaPrimaLitera('I');
        cout << "  Am schimbat doar copia, dar originalul a devenit: "
             << original.getTitlu() << endl;
        cout << "  -- copia este distrusa --" << endl;
    }
    cout << "  -- originalul este distrus: aceeasi memorie e stearsa a doua oara --" << endl;
    cout << "  Programul se va opri cu eroarea 'double free'." << endl;
}

int main()
{
    cout << "Aplicatie Muzica - Tema PAOO" << endl;

    exempluIncapsulare();
    exempluInitializare();
    exempluDestructor();
    exempluCopyConstructor();
    exempluMoveConstructor();

    // Este ultimul, pentru ca opreste programul intentionat
    exempluFaraCopyConstructor();

    return 0;
}
