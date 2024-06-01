//
// Created by Victoire on 27/05/2024.
//

#include "Borrower.h"
#include <iostream>

Borrower::Borrower(const std::string& name) : name(name) {}

std::string Borrower::getName() const {
    return name;
}

void Borrower::displayBorrowerInfo() {
    std::cout << "Borrower Name: " << name << std::endl;
}


