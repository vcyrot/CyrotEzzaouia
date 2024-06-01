//
// Created by Victoire on 27/05/2024.
//

#include "Lender.h"
#include <iostream>

Lender::Lender(const std::string& name) : name(name) {}

std::string Lender::getName() const {
    return name;
}

void Lender::displayLenderInfo() {
    std::cout << "Lender Name: " << name << std::endl;
}
