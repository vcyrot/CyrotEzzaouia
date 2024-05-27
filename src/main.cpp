#include <iostream>
#include "Deal.h"
#include "Facility.h"
#include "Part.h"
#include "Portfolio.h"
#include "Lender.h"
#include "Borrower.h"

int main() {
    // Exemples de création d'objets et d'utilisation des classes
    Borrower borrower("Air France");
    Lender lender1("Banque A");
    Lender lender2("Banque B");

    Facility facility("2024-05-01", "2025-05-01", 500000, "EUR");
    facility.addLender(lender1);
    facility.addLender(lender2);

    Deal deal("SZB1234", "Banque A", {"Banque B"}, borrower, 1000000, "EUR", "2024-05-01", "2026-05-01", "closed");
    deal.addFacility(facility);

    Portfolio portfolio;
    portfolio.addDeal(deal);

    std::cout << "Project setup complete." << std::endl;
    return 0;
}
