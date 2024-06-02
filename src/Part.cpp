#include "Part.h"
#include <iostream>

Part::Part(const std::string& partNumber, const std::string& description, double price)
        : partNumber(partNumber), description(description), price(price) {}

// Define the function as const
void Part::displayPartInfo() const {
    std::cout << "Part Number: " << partNumber << "\n"
              << "Description: " << description << "\n"
              << "Price: " << price << std::endl;
}

<<<<<<< HEAD
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
=======
// Other member functions...
>>>>>>> 0ff6d2f094d48f44e0f8cb025ace3c621b1f36aa
