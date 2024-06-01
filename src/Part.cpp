//
// Created by Victoire on 27/05/2024.
//

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

// Other member functions...
