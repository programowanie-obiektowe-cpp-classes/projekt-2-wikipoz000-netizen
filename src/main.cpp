#include <print>
#include "Czytnik.hpp"
#include "CDData.hpp"

int main() {
    try {
        BazaCD baza;

        // Wczytanie danych z pliku tekstowego lista.txt
        PlytaCD plyta = CzytnikPliku::wczytajZPliku("./data/lista.txt");
        baza.dodajPlyte(std::move(plyta));

        // Policzenie statystyki rozszerzen
        auto statystyki = baza.policzPlikiWedlugRozszerzen();

        std::println("Statystyka plikow wedlug rozszerzen:");
        for (const auto& [rozszerzenie, ilosc] : statystyki) {
            std::println("Liczba plikow typu {} : {}", rozszerzenie, ilosc);
        }

       
        auto cppPliki = baza.znajdzPlikiZRozszerzeniem(".cpp");
        std::println("Pliki z rozszerzeniem .cpp:");

        for (const auto& plik : cppPliki)
        {
            std::println(" - {}", plik.nazwa);
        }
         

        std::println("");
        std::println("Laczna liczba plikow: {}",
            baza.policzWszystkiePliki());
    }
    catch (const std::exception& e) {
        std::println("Blad: {}", e.what());
    }
}
