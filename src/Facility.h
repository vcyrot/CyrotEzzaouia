#ifndef FACILITY_H
#define FACILITY_H

#include <string>
#include <vector>
#include "Person.h"

class Facility {
public:
    Facility(const std::string& startDate, const std::string& endDate, double amount, const std::string& currency,
             const std::vector<Person>& lenders);

    void calculateInterest(double rate, int period);
    void displayFacilityInfo() const;

    // Getters
    std::string getStartDate() const;
    std::string getEndDate() const;
    double getAmount() const;
    double getInterest() const;
    std::string getCurrency() const;
    std::vector<Person> getLenders() const;

    // Setters
    void setStartDate(const std::string& startDate);
    void setEndDate(const std::string& endDate);
    void setAmount(double amount);
    void setInterest(double interest);
    void setCurrency(const std::string& currency);
    void setLenders(const std::vector<Person>& lenders);

private:
    std::string startDate;
    std::string endDate;
    double amount;
    double interest;
    std::string currency;
    std::vector<Person> lenders;
};

#endif // FACILITY_H
