# Muzica - Tema PAOO, Lucrarea 3

Aplicatie simpla in C++ care ilustreaza:

1. build cu CMake
2. incapsulare
3. initializarea membrilor din constructor
4. eliberarea heap-ului in destructor
5. copy constructor
6. move constructor

## Clase

- `Artist` (model/) - nume si gen
- `Melodie` (model/) - titlu pe heap, un Artist, durata
- `Playlist` (colectie/) - nume si melodii pe heap
- `Utilizator` (utilizator/) - nume si un Playlist

Legatura: Utilizator are un Playlist, Playlist are Melodii, Melodie are un Artist.

In `demo/` sunt doua clase scrise gresit intentionat:
`MelodieFaraDestructor` (memory leak) si `MelodieFaraCopyConstructor` (double free).

Ultimul exemplu opreste programul intentionat cu eroarea `double free`,
ca sa arate ce se intampla fara copy constructor.
