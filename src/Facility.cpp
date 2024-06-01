//
// Created by Victoire on 27/05/2024.
//

#include "Facility.h"
#include <iostream>

Facility::Facility(const std::string& startDate, const std::string& endDate, double amount, const std::string& currency,
                   const std::vector<Lender>& lenders)
        : startDate(startDate), endDate(endDate), amount(amount), currency(currency), lenders(lenders) {}

double Facility::calculateInterest(double rate, int period) {
    // Simple interest calculation
    return (amount * rate * period) / 100;
}

void Facility::displayFacilityInfo() {
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout << "End Date: " << endDate << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Currency: " << currency << std::endl;
    std::cout << "Lenders: ";
    for (const auto& lender : lenders) {
        std::cout << lender.getName() << " ";
    }
    std::cout << std::endl;
}

std::string Facility::getStartDate() const {
    return startDate;
}

std::string Facility::getEndDate() const {
    return endDate;
}

double Facility::getAmount() const {
    return amount;
}

std::string Facility::getCurrency() const {
    return currency;
}

std::vector<Lender> Facility::getLenders() const {
    return lenders;
}

