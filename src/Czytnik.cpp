#include "Czytnik.hpp"
#include <fstream>
#include <stdexcept>

PlytaCD CzytnikPliku::wczytajZPliku(const std::string& nazwaPliku) {
    std::ifstream plik(nazwaPliku);

    if (!plik) {
        throw std::runtime_error("Nie mozna otworzyc pliku");
    }

    PlytaCD plyta("CD_1");
    std::string linia;

    while (std::getline(plik, linia)) {
        // Pomijamy puste linie
        if (linia.empty()) continue;

        // Pomijamy katalog glowny "./"
        if (linia == "./") continue;

        // Pomijamy linie opisujace katalogi
        if (linia.ends_with(":")) continue;

        plyta.dodajElement(PlikWejsciowy{
            .nazwa = linia,
            .typ = TypElementu::Plik
            });
    }
    return plyta;
}
