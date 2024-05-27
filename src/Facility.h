//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_FACILITY_H
#define CYROTEZZAOUIA_FACILITY_H

#include <string>
#include <vector>
#include "Lender.h"

class Facility {
public:
    Facility(std::string startDate, std::string endDate, double amount, std::string currency);

    void addLender(Lender lender);
    // autres méthodes

private:
    std::string startDate;
    std::string endDate;
    double amount;
    std::string currency;
    std::vector<Lender> lenders;
};


#endif //CYROTEZZAOUIA_FACILITY_H
