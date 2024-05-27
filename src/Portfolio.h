//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_PORTFOLIO_H
#define CYROTEZZAOUIA_PORTFOLIO_H

#include <vector>
#include "Deal.h"

class Portfolio {
public:
    void addDeal(Deal deal);
    // autres méthodes

private:
    std::vector<Deal> deals;
};

#endif //CYROTEZZAOUIA_PORTFOLIO_H
