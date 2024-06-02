#ifndef PART_H
#define PART_H

#include <string>

class Part {
<<<<<<< HEAD
=======
private:
    std::string partNumber;
    std::string description;
    double price;

>>>>>>> 0ff6d2f094d48f44e0f8cb025ace3c621b1f36aa
public:
    Part(const std::string& partNumber, const std::string& description, double price);

<<<<<<< HEAD
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
=======
    // Mark the function as const
    void displayPartInfo() const;

    // Other member functions...
};

#endif //CYROTEZZAOUIA_PART_H
>>>>>>> 0ff6d2f094d48f44e0f8cb025ace3c621b1f36aa
