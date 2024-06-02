#ifndef PART_H
#define PART_H

#include <string>

class Part {
public:
    Part(double amount, const std::string& facilityId);

    void reduceAmount(double reduction);
    void displayPartInfo() const;

    // Getters
    double getAmount() const;
    std::string getFacilityId() const;

    // Setters
    void setAmount(double amount);
    void setFacilityId(const std::string& facilityId);

private:
    double amount;
    std::string facilityId;
};

#endif // PART_H
