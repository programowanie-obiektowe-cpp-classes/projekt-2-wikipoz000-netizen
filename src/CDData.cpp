#include "CDData.hpp"
#include <ranges>

void BazaCD::dodajPlyte(PlytaCD plyta) {
    plyty.push_back(std::move(plyta));
}

std::vector<PlikWejsciowy>
BazaCD::znajdzPlikiZRozszerzeniem(const std::string& rozszerzenie) const {
    std::vector<PlikWejsciowy> wynik;

    for (const auto& plyta : plyty) {
        auto widok = plyta.pobierzElementy()
            | std::views::filter([&](const PlikWejsciowy& e) {
            return e.nazwa.ends_with(rozszerzenie);
                });

        wynik.insert(wynik.end(), widok.begin(), widok.end());
    }
    return wynik;
}

std::map<std::string, int>
BazaCD::policzPlikiWedlugRozszerzen() const {
    std::map<std::string, int> statystyka;

    for (const auto& plyta : plyty) {
        for (const auto& element : plyta.pobierzElementy()) {

            const std::string& nazwa = element.nazwa;
            auto pozycjaKropki = nazwa.find_last_of('.');

            std::string rozszerzenie;
            if (pozycjaKropki != std::string::npos) {
                rozszerzenie = nazwa.substr(pozycjaKropki);
            }
            else {
                rozszerzenie = "(brak)";
            }

            statystyka[rozszerzenie]++;
        }
    }
    return statystyka;
}

int BazaCD::policzWszystkiePliki() const {
    int suma = 0;
    for (const auto& plyta : plyty) {
        suma += static_cast<int>(plyta.pobierzElementy().size());
    }
    return suma;
}
