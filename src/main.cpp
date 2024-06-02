#include <iostream>
#include <vector>
#include <string>
#include "Deal.h"
#include "Facility.h"
#include "Part.h"
#include "Portfolio.h"
#include "Person.h"

void initializeData(
        std::vector<Deal>& deals,
        std::vector<Facility>& facilities,
        std::vector<Part>& parts,
        std::vector<Person>& persons) {

    // Initialisation des deals
    deals.push_back({"S1234", "Bank A", {"Bank C", "Bank D"}, "Air France", 1000000, "USD", "2024-01-01", "2030-01-01", "closed"});
    deals.push_back({"B5678", "Bank B", {"Bank C", "Bank E"}, "Lufthansa", 2000000, "EUR", "2024-02-01", "2032-02-01", "closed"});
    deals.push_back({"Z4321", "Bank C", {"Bank D", "Bank E"}, "Emirates", 3000000, "USD", "2024-03-01", "2031-03-01", "closed"});

    // Initialisation des facilities
    facilities.push_back({"2024-01-01", "2025-01-01", 500000, "USD", {"Bank C", "Bank D"}});
    facilities.push_back({"2025-01-02", "2026-01-01", 500000, "USD", {"Bank C", "Bank D"}});
    facilities.push_back({"2024-02-01", "2026-02-01", 1000000, "EUR", {"Bank C", "Bank E"}});
    facilities.push_back({"2026-02-02", "2028-02-01", 1000000, "EUR", {"Bank C", "Bank E"}});
    facilities.push_back({"2024-03-01", "2027-03-01", 1500000, "USD", {"Bank D", "Bank E"}});
    facilities.push_back({"2027-03-02", "2030-03-01", 1500000, "USD", {"Bank D", "Bank E"}});

    // Initialisation des parts
    parts.push_back({100000, 5000});
    parts.push_back({200000, 10000});
    parts.push_back({300000, 15000});
    parts.push_back({400000, 20000});
    parts.push_back({500000, 25000});
    parts.push_back({600000, 30000});

    // Initialisation des personnes (lenders et borrowers)
    persons.push_back({"Bank C", Person::Type::Lender, 1000000});
    persons.push_back({"Bank D", Person::Type::Lender, 2000000});
    persons.push_back({"Bank E", Person::Type::Lender, 1500000});

    persons.push_back({"Air France", Person::Type::Borrower, 1000000});
    persons.push_back({"Lufthansa", Person::Type::Borrower, 2000000});
    persons.push_back({"Emirates", Person::Type::Borrower, 3000000});
}

void displayMainMenu() {
    std::cout << "1. Ajouter un deal\n";
    std::cout << "2. Afficher les deals\n";
    std::cout << "3. Ajouter un lender\n";
    std::cout << "4. Afficher les lenders\n";
    std::cout << "5. Ajouter un borrower\n";
    std::cout << "6. Afficher les borrowers\n";
    std::cout << "7. Quitter\n";
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

    deals.push_back({contractNumber, agent, pool, borrowerName, amount, currency, startDate, endDate, status});
    std::cout << "Deal ajouté avec succès." << std::endl;
}

void displayDeals(const std::vector<Deal>& deals) {
    for (const auto& deal : deals) {
        std::cout << "Deal: " << deal.contractNumber
                  << ", Agent: " << deal.agent
                  << ", Borrower: " << deal.borrower
                  << ", Amount: " << deal.projectAmount << " " << deal.currency
                  << ", Status: " << deal.status << std::endl;
    }
}

void addPerson(std::vector<Person>& persons, Person::Type type) {
    std::string name;
    double amount;
    std::cout << "Entrez le nom du " << (type == Person::Type::Lender ? "lender" : "borrower") << ": ";
    std::cin >> name;
    std::cout << "Entrez le montant: ";
    std::cin >> amount;

    persons.push_back({name, type, amount});
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
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl;
        }
    } while (choice != 7);

    return 0;
}
