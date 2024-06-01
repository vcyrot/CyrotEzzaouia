//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_PART_H
#define CYROTEZZAOUIA_PART_H

#include <string>

class Part {
private:
    double amount;
    std::string facilityId;

public:
    Part(double amount, const std::string& facilityId);

    void reduceAmount(double reduction);
    double getAmount() const;
    void displayPartInfo();
    std::string getFacilityId() const;
    // Other necessary methods
};


#endif //CYROTEZZAOUIA_PART_H
