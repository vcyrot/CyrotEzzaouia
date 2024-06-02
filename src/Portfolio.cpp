#include "Portfolio.h"
#include <iostream>

// Ajoute une partie au portefeuille
void Portfolio::addPart(const Part& part) {
    parts.push_back(part);
}

// Affiche les informations du portefeuille
void Portfolio::displayPortfolioInfo() const {
    for (const auto& part : parts) {
        part.displayPartInfo();
    }
}

// Getter pour les parties
std::vector<Part> Portfolio::getParts() const {
    return parts;
}

// Setter pour les parties
void Portfolio::setParts(const std::vector<Part>& parts) {
    this->parts = parts;
}
