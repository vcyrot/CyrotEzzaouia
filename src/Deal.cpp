//
// Created by Victoire on 27/05/2024.
//
#include "Deal.h"

Deal::Deal(std::string number, std::string agent, std::vector<std::string> pool, Borrower borrower, double amount, std::string currency, std::string startDate, std::string endDate, std::string status) :
        number(number), agent(agent), pool(pool), borrower(borrower), amount(amount), currency(currency), startDate(startDate), endDate(endDate), status(status) {}

void Deal::addFacility(Facility facility) {
    facilities.push_back(facility);
}
