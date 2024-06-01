//
// Created by Victoire on 27/05/2024.
//
#include "Deal.h"
#include <iostream>

Deal::Deal(const std::string& contractNumber, const std::string& agent, const std::vector<std::string>& pool,
           const Borrower& borrower, double amount, const std::string& currency,
           const std::string& startDate, const std::string& endDate, const std::string& status)
        : contractNumber(contractNumber), agent(agent), pool(pool), borrower(borrower),
          amount(amount), currency(currency), startDate(startDate), endDate(endDate), status(status) {}

void Deal::displayDealInfo() {
    std::cout << "Contract Number: " << contractNumber << std::endl;
    std::cout << "Agent: " << agent << std::endl;
    std::cout << "Pool: ";
    for (const auto& p : pool) {
        std::cout << p << " ";
    }
    std::cout << std::endl;
    std::cout << "Borrower: " << borrower.getName() << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Currency: " << currency << std::endl;
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout << "End Date: " << endDate << std::endl;
    std::cout << "Status: " << status << std::endl;
}

std::string Deal::getContractNumber() const {
    return contractNumber;
}
