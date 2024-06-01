//
// Created by Victoire on 27/05/2024.
//

#ifndef CYROTEZZAOUIA_BORROWER_H
#define CYROTEZZAOUIA_BORROWER_H

#include <string>

class Borrower {
private:
    std::string name;

public:
    Borrower(const std::string& name);

    std::string getName() const;
    void displayBorrowerInfo();
    // Other necessary methods
};

#endif //CYROTEZZAOUIA_BORROWER_H
