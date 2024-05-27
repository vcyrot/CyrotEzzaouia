//
// Created by Victoire on 27/05/2024.
//

#include "Part.h"

Part::Part(double amount) : amount(amount) {}

void Part::makePayment(double payment) {
    amount -= payment;
}

