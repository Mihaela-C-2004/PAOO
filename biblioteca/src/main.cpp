#include <util/registru.hpp>
#include <model/carte.hpp>
#include <model/carte_digitala.hpp>
#include <imprumut/imprumut.hpp>
#include <cititor/permis_cititor.hpp>
#include <demo/exemple_gresite.hpp>

#include <iostream>

using namespace std;

// Item 4: obiect GLOBAL. Este creat INAINTE de main().
// Constructorul lui foloseste registrul, care e definit in alt fisier (registru.cpp).
// Pentru ca ajungem la registru prin functia registru(), el e creat exact
// in momentul in care e nevoie de el, deci nu poate fi folosit inainte sa existe.
Carte carteGlobala("Regulamentul bibliotecii", 10);

void titlu(const char* text)
{
    cout << endl << "========== " << text << " ==========" << endl;
}

// Afiseaza un text, inlocuind caracterele care nu se pot afisa cu '?'
// (folosit la Item 11, unde titlul stricat contine gunoi din memorie)
void afiseazaSigur(const char* text)
{
    for (int i = 0; text[i] != '\0' && i < 20; i++) {
        if (text[i] >= 32 && text[i] <= 126) {
            cout << text[i];
        } else {
            cout << '?';
        }
    }
}

// ---------------------------------------------------------------
// Item 4: initializarea obiectelor inainte de folosire
// ---------------------------------------------------------------
void item4()
{
    titlu("Item 4: Initializarea obiectelor inainte de folosire");

    cout << "  a) Membru de tip int NEinitializat:" << endl;
    CarteNeinitializata gresit(300);
    cout << "     numarImprumuturi = " << gresit.getNumarImprumuturi()
         << "  <-- valoare intamplatoare (gunoi din memorie)" << endl;

    cout << endl << "  b) Toti membrii initializati in lista de initializare:" << endl;
    Carte corect;
    cout << "     ";
    corect.afiseaza();
    cout << "  <-- valori cunoscute" << endl;

    cout << endl << "  c) Obiect static local in loc de obiect global:" << endl;
    cout << "     Registrul a fost creat INAINTE de main(), la prima folosire," << endl;
    cout << "     de catre constructorul obiectului global carteGlobala." << endl;
    cout << "     Carti create pana acum: " << registru().getNumarCarti() << endl;
}

// ---------------------------------------------------------------
// Item 5: functiile scrise si apelate in secret de compilator
// ---------------------------------------------------------------
void item5()
{
    titlu("Item 5: Functiile scrise automat de compilator");

    cout << "  Imprumut NU are copy constructor, operator= sau destructor scrise de noi." << endl;
    Carte c1("Ion", 280);
    Carte c2("Enigma Otiliei", 420);
    Imprumut i1("Ana", 14, c1);
    Imprumut i2("Mihai", 7, c2);

    cout << endl << "  -- Imprumut i3 = i1;  (copy constructor scris de compilator) --" << endl;
    Imprumut i3 = i1;
    cout << "  Nu apare [Imprumut] Constructor: copia a fost facuta de functia" << endl;
    cout << "  scrisa de compilator, care a apelat copy constructor-ul din Carte." << endl;

    cout << endl << "  -- i3 = i2;  (operator= scris de compilator) --" << endl;
    i3 = i2;
    i3.afiseaza();

    cout << endl << "  Compilatorul a apelat singur functiile din Carte (vezi mesajele)." << endl;
    cout << "  Nu exista constructor implicit: Imprumut gol; da eroare," << endl;
    cout << "  pentru ca am declarat noi un constructor." << endl;
    cout << "  -- la iesire, destructorul scris de compilator sterge si Carte --" << endl;
}

// ---------------------------------------------------------------
// Item 6: interzicerea functiilor generate de compilator
// ---------------------------------------------------------------
void item6()
{
    titlu("Item 6: Interzicerea copierii");

    Carte c("Morometii", 350);
    Imprumut imprumut("Ana", 21, c);
    PermisCititor ana(1, "Ana", imprumut);
    ana.afiseaza();

    // Liniile de mai jos NU compileaza:
    // PermisCititor copie = ana;
    //     error: use of deleted function 'PermisCititor::PermisCititor(const PermisCititor&)'
    // ana = alt;
    //     error: use of deleted function 'PermisCititor& PermisCititor::operator=(...)'
    cout << "  PermisCititor copie = ana;  NU compileaza (use of deleted function)." << endl;
    cout << "  Asa nu pot exista doua permise cu acelasi numar." << endl;
}

// ---------------------------------------------------------------
// Item 10: operator= returneaza o referinta la *this
// ---------------------------------------------------------------
void item10()
{
    titlu("Item 10: operator= returneaza *this");

    Carte a("A", 100);
    Carte b("B", 200);
    Carte c("C", 300);

    cout << "  -- a = b = c;  (se executa de la dreapta la stanga: a = (b = c)) --" << endl;
    a = b = c;
    cout << "  a: "; a.afiseaza(); cout << endl;
    cout << "  b: "; b.afiseaza(); cout << endl;
    cout << "  c: "; c.afiseaza(); cout << endl;

    // Cu operator= care returneaza void, linia de mai jos NU compileaza:
    // x = y = z;
    //     error: no match for 'operator=' (operand types are 'CarteAtribuireGresita' and 'void')
    cout << "  Daca operator= ar returna void, a = b = c; nu ar compila." << endl;
}

// ---------------------------------------------------------------
// Item 11: auto-atribuirea in operator=
// ---------------------------------------------------------------
void item11()
{
    titlu("Item 11: Auto-atribuirea (c = c)");

    cout << "  a) Corect (Carte verifica this == &other):" << endl;
    Carte c("Amintiri din copilarie", 150);
    Carte& aceeasi = c;   // alta denumire pentru acelasi obiect
    c = aceeasi;
    cout << "     Dupa c = c: \"" << c.getTitlu() << "\"" << endl;

    cout << endl << "  b) Gresit (sterge titlul, apoi il citeste din obiectul sters):" << endl;
    CarteAtribuireGresita g("Baltagul");
    CarteAtribuireGresita& aceeasiG = g;
    g = aceeasiG;
    cout << "     Dupa g = g: \"";
    afiseazaSigur(g.getTitlu());
    cout << "\"  <-- titlul s-a stricat (comportament nedefinit)" << endl;
}

// ---------------------------------------------------------------
// Item 12: copierea tuturor partilor unui obiect
// ---------------------------------------------------------------
void item12()
{
    titlu("Item 12: Copierea tuturor partilor obiectului");

    cout << "  a) Corect (CarteDigitala apeleaza Carte(other) si Carte::operator=):" << endl;
    CarteDigitala d1("Maitreyi", 200, "PDF");
    CarteDigitala d2 = d1;
    cout << "     copie: "; d2.afiseaza(); cout << endl;

    CarteDigitala d3("Luceafarul", 40, "EPUB");
    d3 = d1;
    cout << "     dupa atribuire: "; d3.afiseaza(); cout << endl;

    cout << endl << "  b) Gresit (copiaza doar formatul, uita partea de baza):" << endl;
    CarteDigitalaGresita g1("Maitreyi", 200, "PDF");
    CarteDigitalaGresita g2 = g1;
    cout << "     copie: "; g2.afiseaza(); cout << "  <-- titlul s-a pierdut" << endl;

    CarteDigitalaGresita g3("Luceafarul", 40, "EPUB");
    g3 = g1;
    cout << "     dupa atribuire: "; g3.afiseaza();
    cout << "  <-- titlul a ramas cel vechi" << endl;
}

int main()
{
    cout << endl << "Aplicatie Biblioteca - Lucrarile 4 si 5 (Effective C++)" << endl;

    item4();
    item5();
    item6();
    item10();
    item11();
    item12();

    cout << endl << "========== Sfarsit ==========" << endl;
    return 0;
}
