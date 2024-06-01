//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_FACILITY_H
#define CYROTEZZAOUIA_FACILITY_H


#include <string>
#include <vector>
#include "Lender.h"

class Facility {
private:
    std::string startDate;
    std::string endDate;
    double amount;
    std::string currency;
    std::vector<Lender> lenders;

public:
    Facility(const std::string& startDate, const std::string& endDate, double amount, const std::string& currency,
             const std::vector<Lender>& lenders);

    double calculateInterest(double rate, int period); // Example method for interest calculation
    void displayFacilityInfo();
    std::string getStartDate() const;
    std::string getEndDate() const;
    double getAmount() const;
    std::string getCurrency() const;
    std::vector<Lender> getLenders() const;
    // Other necessary methods
};



#endif //CYROTEZZAOUIA_FACILITY_H
