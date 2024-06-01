//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_LENDER_H
#define CYROTEZZAOUIA_LENDER_H

#include <string>

class Lender {
private:
    std::string name;

public:
    Lender(const std::string& name);

    std::string getName() const;
    void displayLenderInfo();
    // Other necessary methods
};

#endif //CYROTEZZAOUIA_LENDER_H
