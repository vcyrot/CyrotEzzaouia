#include "Portfolio.h"
#include <iostream>

void Portfolio::addPart(const Part& part) {
    parts.push_back(part);
}

void Portfolio::displayPortfolioInfo() const {
    for (const auto& part : parts) {
        part.displayPartInfo();
    }
}

std::vector<Part> Portfolio::getParts() const {
    return parts;
}

void Portfolio::setParts(const std::vector<Part>& parts) {
    this->parts = parts;
}
