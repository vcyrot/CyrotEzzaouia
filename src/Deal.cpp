#include "Deal.h"
#include <iostream>

Deal::Deal(const std::string& contractNumber, const std::string& agent, const std::vector<std::string>& pool,
           const Person& borrower, double amount, const std::string& currency,
           const std::string& startDate, const std::string& endDate, const std::string& status)
        : contractNumber(contractNumber), agent(agent), pool(pool), borrower(borrower),
          amount(amount), currency(currency), startDate(startDate), endDate(endDate), status(status) {}

void Deal::displayDealInfo() const {
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

// Getters
std::string Deal::getContractNumber() const {
    return contractNumber;
}

<<<<<<< HEAD
std::string Deal::getAgent() const {
    return agent;
}

std::vector<std::string> Deal::getPool() const {
    return pool;
}

Person Deal::getBorrower() const {
    return borrower;
}

double Deal::getAmount() const {
    return amount;
}

std::string Deal::getCurrency() const {
    return currency;
}

std::string Deal::getStartDate() const {
    return startDate;
}

std::string Deal::getEndDate() const {
    return endDate;
}

std::string Deal::getStatus() const {
    return status;
}

// Setters
void Deal::setContractNumber(const std::string& contractNumber) {
    this->contractNumber = contractNumber;
}

void Deal::setAgent(const std::string& agent) {
    this->agent = agent;
}

void Deal::setPool(const std::vector<std::string>& pool) {
    this->pool = pool;
}

void Deal::setBorrower(const Person& borrower) {
    this->borrower = borrower;
}

void Deal::setAmount(double amount) {
    this->amount = amount;
}

void Deal::setCurrency(const std::string& currency) {
    this->currency = currency;
}

void Deal::setStartDate(const std::string& startDate) {
    this->startDate = startDate;
}

void Deal::setEndDate(const std::string& endDate) {
    this->endDate = endDate;
}

void Deal::setStatus(const std::string& status) {
    this->status = status;
}
=======
>>>>>>> 0ff6d2f094d48f44e0f8cb025ace3c621b1f36aa
