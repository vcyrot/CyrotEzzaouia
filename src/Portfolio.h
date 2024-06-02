#ifndef PORTFOLIO_H
#define PORTFOLIO_H

#include "Part.h"
#include <vector>

class Portfolio {
public:
    // Methodes
    void addPart(const Part& part);
    void displayPortfolioInfo() const;

    // Getters
    std::vector<Part> getParts() const;

    // Setters
    void setParts(const std::vector<Part>& parts);

private:
    std::vector<Part> parts;
};

#endif // PORTFOLIO_H
