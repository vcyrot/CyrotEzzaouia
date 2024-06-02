#include "Facility.h"
#include <iostream>

Facility::Facility(const std::string& startDate, const std::string& endDate, double amount, const std::string& currency,
                   const std::vector<Person>& lenders)
        : startDate(startDate), endDate(endDate), amount(amount), currency(currency), lenders(lenders), interest(0) {}

void Facility::calculateInterest(double rate, int period) {
    // Simple interest calculation
    interest =  (amount * rate * period) / 100;
}

void Facility::displayFacilityInfo() const {
    std::cout << "Start Date: " << startDate << std::endl;
    std::cout << "End Date: " << endDate << std::endl;
    std::cout << "Amount: " << amount << std::endl;
    std::cout << "Interest: " << interest << std::endl;
    std::cout << "Currency: " << currency << std::endl;
    std::cout << "Lenders: ";
    for (const auto& lender : lenders) {
        std::cout << lender.getName() << " ";
    }
    std::cout << std::endl;
}

// Getters
std::string Facility::getStartDate() const {
    return startDate;
}

std::string Facility::getEndDate() const {
    return endDate;
}

double Facility::getAmount() const {
    return amount;
}

double Facility::getInterest() const {
    return interest;
}

std::string Facility::getCurrency() const {
    return currency;
}

std::vector<Person> Facility::getLenders() const {
    return lenders;
}

// Setters
void Facility::setStartDate(const std::string& startDate) {
    this->startDate = startDate;
}

void Facility::setEndDate(const std::string& endDate) {
    this->endDate = endDate;
}

void Facility::setAmount(double amount) {
    this->amount = amount;
}

void Facility::setInterest(double interest) {
    this->interest = interest;
}

void Facility::setCurrency(const std::string& currency) {
    this->currency = currency;
}

void Facility::setLenders(const std::vector<Person>& lenders) {
    this->lenders = lenders;
}
