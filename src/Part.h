//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_PART_H
#define CYROTEZZAOUIA_PART_H

#include <string>

class Part {
private:
    std::string partNumber;
    std::string description;
    double price;

public:
    Part(const std::string& partNumber, const std::string& description, double price);

    // Mark the function as const
    void displayPartInfo() const;

    // Other member functions...
};

#endif //CYROTEZZAOUIA_PART_H
