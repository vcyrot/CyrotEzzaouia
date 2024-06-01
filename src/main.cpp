#include <iostream>
#include <vector>
#include <string>
#include "Database.h"
#include "Deal.h"
#include "Facility.h"
#include "Part.h"
#include "Portfolio.h"
#include "Lender.h"
#include "Borrower.h"

void displayMainMenu() {
    std::cout << "1. Ajouter un deal\n";
    std::cout << "2. Afficher les deals\n";
    std::cout << "3. Ajouter un lender\n";
    std::cout << "4. Afficher les lenders\n";
    std::cout << "5. Quitter\n";
    std::cout << "Choisissez une option: ";
}

void addDeal(Database& db) {
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

    Borrower borrower(borrowerName);
    std::vector<std::string> pool;

    std::cout << "Entrez le nombre de pool: ";
    std::cin >> poolSize;
    for (int i = 0; i < poolSize; ++i) {
        std::string poolItem;
        std::cout << "Entrez le pool item " << i + 1 << ": ";
        std::cin >> poolItem;
        pool.push_back(poolItem);
    }

    Deal deal(contractNumber, agent, pool, borrower, amount, currency, startDate, endDate, status);
    std::string query = "INSERT INTO deals (contract_number, agent, pool, borrower, amount, currency, start_date, end_date, status) VALUES ('"
                        + contractNumber + "', '" + agent + "', '" + borrowerName + "', " + std::to_string(amount) + ", '"
                        + currency + "', '" + startDate + "', '" + endDate + "', '" + status + "')";

    if (db.executeQuery(query)) {
        std::cout << "Deal ajouté avec succès." << std::endl;
    }
}

void displayDeals(Database& db) {
    std::string query = "SELECT * FROM deals";
    auto results = db.fetchResults(query);

    for (const auto& row : results) {
        for (const auto& field : row) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }
}

void addLender(Database& db) {
    std::string name;
    std::cout << "Entrez le nom du lender: ";
    std::cin >> name;

    std::string query = "INSERT INTO lenders (name) VALUES ('" + name + "')";
    if (db.executeQuery(query)) {
        std::cout << "Lender ajouté avec succès." << std::endl;
    }
}

void displayLenders(Database& db) {
    std::string query = "SELECT * FROM lenders";
    auto results = db.fetchResults(query);

    for (const auto& row : results) {
        for (const auto& field : row) {
            std::cout << field << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    Database db("localhost", "cyrotezzaouia", "cyrotezzaouia", "DatabaseProject");

    int choice;
    do {
        displayMainMenu();
        std::cin >> choice;

        switch (choice) {
            case 1:
                addDeal(db);
                break;
            case 2:
                displayDeals(db);
                break;
            case 3:
                addLender(db);
                break;
            case 4:
                displayLenders(db);
                break;
            case 5:
                std::cout << "Au revoir!" << std::endl;
                break;
            default:
                std::cout << "Choix invalide, veuillez réessayer." << std::endl;
        }
    } while (choice != 5);

    return 0;
}

