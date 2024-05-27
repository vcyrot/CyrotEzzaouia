//
// Created by Victoire on 27/05/2024.
//

#include "Facility.h"

Facility::Facility(std::string startDate, std::string endDate, double amount, std::string currency) :
        startDate(startDate), endDate(endDate), amount(amount), currency(currency) {}

void Facility::addLender(Lender lender) {
    lenders.push_back(lender);
}

