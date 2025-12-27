#pragma once
#include <vector>
#include <map>
#include <string>
#include "CD.hpp"

//Klasa reprezentuj¹ca bazê danych p³yt CD

class BazaCD {
public:
    void dodajPlyte(PlytaCD plyta);

    std::vector<PlikWejsciowy> znajdzPlikiZRozszerzeniem(const std::string& rozszerzenie) const;
    std::map<std::string, int> policzPlikiWedlugRozszerzen() const;
    int policzWszystkiePliki() const;

private:
    std::vector<PlytaCD> plyty;
};
