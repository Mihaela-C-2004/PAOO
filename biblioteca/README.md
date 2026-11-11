# Biblioteca - Lucrarile 4 si 5 (Effective C++)

Aplicatie simpla in C++ care ilustreaza item-urile din cartea Effective C++:

- Item 4: Make sure that objects are initialized before they're used
- Item 5: Know what functions C++ silently writes and calls
- Item 6: Explicitly disallow the use of compiler generated functions you do not want
- Item 10: Have assignment operators return a reference to *this
- Item 11: Handle assignment to self in operator=
- Item 12: Copy all parts of an object

## Clase

- `Registru` (util/) - numara cartile; folosit prin functia `registru()` (Item 4)
- `Carte` (model/) - titlu pe heap si numar de pagini; operator= corect (Item 4, 10, 11)
- `CarteDigitala` (model/) - mosteneste Carte, adauga formatul (Item 12)
- `Imprumut` (imprumut/) - cititor, zile, carte; fara functii de copiere scrise (Item 5)
- `PermisCititor` (cititor/) - permis unic, copierea este interzisa cu `= delete` (Item 6)

Legatura: PermisCititor are un Imprumut, Imprumut are o Carte, CarteDigitala este o Carte.

In `demo/` sunt clasele scrise gresit intentionat:
`CarteNeinitializata` (Item 4), `CarteAtribuireGresita` (Item 10, 11),
`CarteDigitalaGresita` (Item 12).

## Rulare

```bash
mkdir build
cd build
cmake ..
make
./biblioteca
```
