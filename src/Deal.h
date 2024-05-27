//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_DEAL_H
#define CYROTEZZAOUIA_DEAL_H

#include <string>
#include <vector>
#include "Facility.h"
#include "Borrower.h"

class Deal {
public:
    Deal(std::string number, std::string agent, std::vector<std::string> pool, Borrower borrower, double amount, std::string currency, std::string startDate, std::string endDate, std::string status);

    void addFacility(Facility facility);
    // autres méthodes

private:
    std::string number;
    std::string agent;
    std::vector<std::string> pool;
    Borrower borrower;
    double amount;
    std::string currency;
    std::string startDate;
    std::string endDate;
    std::string status;
    std::vector<Facility> facilities;
};



#endif //CYROTEZZAOUIA_DEAL_H
