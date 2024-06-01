//
// Created by Victoire on 27/05/2024.
//

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

double Part::getAmount() const {
    return amount;
}

void Part::displayPartInfo() {
    std::cout << "Facility ID: " << facilityId << std::endl;
    std::cout << "Amount: " << amount << std::endl;
}

std::string Part::getFacilityId() const {
    return facilityId;
}