#include "Part.h"
#include <iostream>

Part::Part(const std::string& partNumber, double price)
        : partNumber(partNumber), price(price) {}

// Define the function as const
void Part::displayPartInfo() const {
    std::cout << "Part Number: " << partNumber << "\n"
              << "Price: " << price << std::endl;
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
