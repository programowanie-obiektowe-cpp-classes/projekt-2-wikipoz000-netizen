#pragma once
#include <string>
#include <vector>
#include "Wejscie.hpp"

//Klasa reprezentuj¹ca jedn¹ p³ytê CD
class PlytaCD {
public:
    explicit PlytaCD(std::string nazwa);

    void dodajElement(const PlikWejsciowy& element);
    const std::vector<PlikWejsciowy>& pobierzElementy() const;

private:
    std::string nazwaPlyty;
    std::vector<PlikWejsciowy> elementy;
};
