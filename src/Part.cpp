#include "Part.h"
#include <iostream>

Part::Part(double amount, const std::string& facilityId) : amount(amount), facilityId(facilityId) {}

void Part::reduceAmount(double reduction) {
    if (reduction <= amount) {
        amount -= reduction;
    } else {
        std::cout << "Reduction amount exceeds the current part amount." << std::endl;
    }
}

void Part::displayPartInfo() const {
    std::cout << "Facility ID: " << facilityId << std::endl;
    std::cout << "Amount: " << amount << std::endl;
}

// Getters
double Part::getAmount() const {
    return amount;
}

std::string Part::getFacilityId() const {
    return facilityId;
}

// Setters
void Part::setAmount(double amount) {
    this->amount = amount;
}

void Part::setFacilityId(const std::string& facilityId) {
    this->facilityId = facilityId;
}
