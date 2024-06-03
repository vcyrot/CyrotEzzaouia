#include <iostream>
#include <vector>
#include <string>
#include "Deal.h"
#include "Facility.h"
#include "Part.h"
#include "Person.h"
#include "Portfolio.h"

void initializeData(
        std::vector<Deal>& deals,
        std::vector<Facility>& facilities,
        std::vector<Part>& parts,
        std::vector<Person>& persons) {

    // Initialisation des deals
    deals.push_back(Deal("S1234", "Bank A", {"Bank C", "Bank D"}, Person("Air France", Person::Type::Borrower), 1000000, "USD", "2024-01-01", "2030-01-01", "closed"));
    deals.push_back(Deal("B5678", "Bank B", {"Bank C", "Bank E"}, Person("Lufthansa", Person::Type::Borrower), 2000000, "EUR", "2024-02-01", "2032-02-01", "closed"));
    deals.push_back(Deal("Z4321", "Bank C", {"Bank D", "Bank E"}, Person("Emirates", Person::Type::Borrower), 3000000, "USD", "2024-03-01", "2031-03-01", "closed"));

    // Initialisation des facilities
    facilities.push_back(Facility("2024-01-01", "2025-01-01", 500000, "USD", {Person("Bank C", Person::Type::Lender), Person("Bank D", Person::Type::Lender)}));
    facilities.push_back(Facility("2025-01-02", "2026-01-01", 500000, "USD", {Person("Bank C", Person::Type::Lender), Person("Bank D", Person::Type::Lender)}));
    facilities.push_back(Facility("2024-02-01", "2026-02-01", 1000000, "EUR", {Person("Bank C", Person::Type::Lender), Person("Bank E", Person::Type::Lender)}));
    facilities.push_back(Facility("2026-02-02", "2028-02-01", 1000000, "EUR", {Person("Bank C", Person::Type::Lender), Person("Bank E", Person::Type::Lender)}));
    facilities.push_back(Facility("2024-03-01", "2027-03-01", 1500000, "USD", {Person("Bank D", Person::Type::Lender), Person("Bank E", Person::Type::Lender)}));
    facilities.push_back(Facility("2027-03-02", "2030-03-01", 1500000, "USD", {Person("Bank D", Person::Type::Lender), Person("Bank E", Person::Type::Lender)}));

    // Initialisation des parts
    parts.push_back(Part("S1234", 100000));
    parts.push_back(Part("B5678", 200000));
    parts.push_back(Part("Z4321", 300000));
    parts.push_back(Part("S1234", 400000));
    parts.push_back(Part("B5678", 500000));
    parts.push_back(Part("Z4321", 600000));

    // Initialisation des personnes (lenders et borrowers)
    persons.push_back(Person("Bank C", Person::Type::Lender));
    persons.push_back(Person("Bank D", Person::Type::Lender));
    persons.push_back(Person("Bank E", Person::Type::Lender));

    persons.push_back(Person("Air France", Person::Type::Borrower));
    persons.push_back(Person("Lufthansa", Person::Type::Borrower));
    persons.push_back(Person("Emirates", Person::Type::Borrower));
}

void displayMainMenu() {
    std::cout << "1. Ajouter un deal\n";
    std::cout << "2. Afficher les deals\n";
    std::cout << "3. Ajouter un lender\n";
    std::cout << "4. Afficher les lenders\n";
    std::cout << "5. Ajouter un borrower\n";
    std::cout << "6. Afficher les borrowers\n";
    std::cout << "7. Modifier un deal\n";
    std::cout << "8. Supprimer un deal\n";
    std::cout << "9. Rechercher des deals par borrower\n";
    std::cout << "10. Quitter\n";
    std::cout << "Choisissez une option: ";
}

void addDeal(std::vector<Deal>& deals, const std::vector<Person>& persons) {
    std::string contractNumber, agent, currency, startDate, endDate, status, borrowerName;
    double amount;
    int poolSize;

    std::cout << "Entrez le numéro de contrat: ";
    std::cin >> contractNumber;
    std::cout << "Entrez l'agent: ";
    std::cin >> agent;
    std::cout << "Entrez la monnaie: ";
    std::cin >> currency;
    std::cout << "Entrez la date de début: ";
    std::cin >> startDate;
    std::cout << "Entrez la date de fin: ";
    std::cin >> endDate;
    std::cout << "Entrez le statut: ";
    std::cin >> status;
    std::cout << "Entrez le montant: ";
    std::cin >> amount;
    std::cout << "Entrez le nom du borrower: ";
    std::cin >> borrowerName;

    bool borrowerFound = false;
    for (const auto& person : persons) {
        if (person.getName() == borrowerName && person.getType() == Person::Type::Borrower) {
            borrowerFound = true;
            break;
        }
    }

    if (!borrowerFound) {
        std::cout << "Borrower not found." << std::endl;
        return;
    }

    std::vector<std::string> pool;
    std::cout << "Entrez le nombre de pool: ";
    std::cin >> poolSize;
    for (int i = 0; i < poolSize; ++i) {
        std::string poolItem;
        std::cout << "Entrez le pool item " << i + 1 << ": ";
        std::cin >> poolItem;
        pool.push_back(poolItem);
    }

    deals.push_back(Deal(contractNumber, agent, pool, Person(borrowerName, Person::Type::Borrower), amount, currency, startDate, endDate, status));
    std::cout << "Deal ajouté avec succès." << std::endl;
}

void displayDeals(const std::vector<Deal>& deals) {
    for (const auto& deal : deals) {
        deal.displayDealInfo();
    }
}

void addPerson(std::vector<Person>& persons, Person::Type type) {
    std::string name;
    double amount;
    std::cout << "Entrez le nom du " << (type == Person::Type::Lender ? "lender" : "borrower") << ": ";
    std::cin >> name;
    std::cout << "Entrez le montant: ";
    std::cin >> amount;

    persons.push_back(Person(name, type));
    std::cout << (type == Person::Type::Lender ? "Lender" : "Borrower") << " ajouté avec succès." << std::endl;
}

void displayPersons(const std::vector<Person>& persons, Person::Type type) {
    std::cout << (type == Person::Type::Lender ? "Lenders" : "Borrowers") << ":" << std::endl;
    for (const auto& person : persons) {
        if (person.getType() == type) {
            person.displayInfo();
        }
    }
}

void updateDeal(std::vector<Deal>& deals) {
    std::string contractNumber;
    std::cout << "Entrez le numéro de contrat du deal à modifier: ";
    std::cin >> contractNumber;

    for (auto& deal : deals) {
        if (deal.getContractNumber() == contractNumber) {
            std::string agent, currency, startDate, endDate, status;
            double amount;

            std::cout << "Entrez le nouvel agent: ";
            std::cin >> agent;
            std::cout << "Entrez la nouvelle monnaie: ";
            std::cin >> currency;
            std::cout << "Entrez la nouvelle date de début: ";
            std::cin >> startDate;
            std::cout << "Entrez la nouvelle date de fin: ";
            std::cin >> endDate;
            std::cout << "Entrez le nouveau statut: ";
            std::cin >> status;
            std::cout << "Entrez le nouveau montant: ";
            std::cin >> amount;

            deal.setAgent(agent);
            deal.setCurrency(currency);
            deal.setStartDate(startDate);
            deal.setEndDate(endDate);
            deal.setStatus(status);
            deal.setAmount(amount);

            std::cout << "Deal mis à jour avec succès." << std::endl;
            return;
        }
    }

    std::cout << "Deal non trouvé." << std::endl;
}

void deleteDeal(std::vector<Deal>& deals) {
    std::string contractNumber;
    std::cout << "Entrez le numéro de contrat du deal à supprimer: ";
    std::cin >> contractNumber;

    for (auto it = deals.begin(); it != deals.end(); ++it) {
        if (it->getContractNumber() == contractNumber) {
            deals.erase(it);
            std::cout << "Deal supprimé avec succès." << std::endl;
            return;
        }
    }

    std::cout << "Deal non trouvé." << std::endl;
}

void searchDealsByBorrower(const std::vector<Deal>& deals) {
    std::string borrowerName;
    std::cout << "Entrez le nom du borrower pour rechercher les deals: ";
    std::cin >> borrowerName;

    bool found = false;
    for (const auto& deal : deals) {
        if (deal.getBorrower().getName() == borrowerName) {
            deal.displayDealInfo();
            found = true;
        }
    }

    if (!found) {
        std::cout << "Aucun deal trouvé pour ce borrower." << std::endl;
    }
}


int main() {
    std::vector<Deal> deals;
    std::vector<Facility> facilities;
    std::vector<Part> parts;
    std::vector<Person> persons;

    initializeData(deals, facilities, parts, persons);

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addDeal(deals, persons);
                break;
            case 2:
                displayDeals(deals);
                break;
            case 3:
                addPerson(persons, Person::Type::Lender);
                break;
            case 4:
                displayPersons(persons, Person::Type::Lender);
                break;
            case 5:
                addPerson(persons, Person::Type::Borrower);
                break;
            case 6:
                displayPersons(persons, Person::Type::Borrower);
                break;
            case 7:
                updateDeal(deals);
                break;
            case 8:
                deleteDeal(deals);
                break;
            case 9:
                searchDealsByBorrower(deals);
                break;
            case 10:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl;
        }
    } while (choice != 10);

    return 0;
}

