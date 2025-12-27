#pragma once
#include <string>
#include "CD.hpp"

//Klasa odpowiedzialna za wczytanie danych z pliku tekstowego

class CzytnikPliku {
public:
    static PlytaCD wczytajZPliku(const std::string& nazwaPliku);
};
