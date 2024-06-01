//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_PORTFOLIO_H
#define CYROTEZZAOUIA_PORTFOLIO_H

#include <vector>
#include "Part.h"

class Portfolio {
private:
    std::vector<Part> parts;

public:
    void addPart(const Part& part);
    void displayPortfolioInfo();
    std::vector<Part> getParts() const;
    // Other necessary methods
};

#endif //CYROTEZZAOUIA_PORTFOLIO_H
