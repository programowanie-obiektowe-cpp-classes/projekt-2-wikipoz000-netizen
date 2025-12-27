#include "CD.hpp"

PlytaCD::PlytaCD(std::string nazwa)
    : nazwaPlyty(std::move(nazwa)) {
}

void PlytaCD::dodajElement(const PlikWejsciowy& element) {
    elementy.push_back(element);
}

const std::vector<PlikWejsciowy>& PlytaCD::pobierzElementy() const {
    return elementy;
}
