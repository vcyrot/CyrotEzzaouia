//
// Created by Victoire on 27/05/2024.
//

#include "Portfolio.h"
#include <iostream>

void Portfolio::addPart(const Part& part) {
    parts.push_back(part);
}

void Portfolio::displayPortfolioInfo() {
    for (const auto& part : parts) {
        part.displayPartInfo();
    }
}

std::vector<Part> Portfolio::getParts() const {
    return parts;
}
