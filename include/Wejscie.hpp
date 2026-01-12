#pragma once
#include <string>

//Typ elementu znajduj¹cego siê na p³ycie
enum class TypElementu {
    Plik,
    Katalog
};

//Reprezentuje jeden plik
struct PlikWejsciowy {
    std::string nazwa;                 // nazwa pliku
    TypElementu typ = TypElementu::Plik;
};
