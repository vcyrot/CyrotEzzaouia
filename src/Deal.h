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
private:
    std::string contractNumber;
    std::string agent;
    std::vector<std::string> pool;
    Borrower borrower;
    double amount;
    std::string currency;
    std::string startDate;
    std::string endDate;
    std::string status;

public:
    Deal(const std::string& contractNumber, const std::string& agent, const std::vector<std::string>& pool,
         const Borrower& borrower, double amount, const std::string& currency,
         const std::string& startDate, const std::string& endDate, const std::string& status);

    void displayDealInfo();
    std::string getContractNumber() const;
    // Other necessary methods
};

#endif //CYROTEZZAOUIA_DEAL_H
